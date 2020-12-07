#include <stdio.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>

#define MAX_TABLES 100
#define MAX_LIMIT 1000


struct Customer
{
 char  customerName [10];
};

struct Table
{
 int tableNo;
 bool available;
 int capacity;
 struct Customer guests[6];
 int noOfGuests;
 int noOfTotalGuests;
 sem_t waitForAll;
};

struct Restaurant
{

 int mealTime;
 struct Table tables[MAX_TABLES];
 int totalTables;
char reminderBook[MAX_LIMIT][6][10];
int noOfGroups;
int noOfPeopleServed;
sem_t closure;

};


int main(int argc,char*argv[])
{
   struct Restaurant *restaurant;
   
   

  int id_sem=shmget(1250, 1024, 0666 | IPC_CREAT | IPC_EXCL);
  int id_sem1=shmget(1251, 1024, 0666 | IPC_CREAT | IPC_EXCL);
  int id_sem2=shmget(1252, 1024, 0666 | IPC_CREAT | IPC_EXCL);
  int id_cs= shmget(1253, sizeof(struct Restaurant),  0666| IPC_CREAT | IPC_EXCL);

  sem_t *closeRestaurant;
  sem_t *eatMeal;
  sem_t *mutex;
 
  if (id_sem==-1 || id_cs==-1|| id_sem1==-1 ||id_sem2 ==-1)
  {
   
    printf("ERROR!");
    return 1;
    
  }



closeRestaurant= (sem_t*) shmat(id_sem, NULL, 0);
eatMeal= (sem_t*) shmat(id_sem1, NULL, 0);
mutex= (sem_t*) shmat(id_sem2, NULL, 0);
restaurant= (struct Restaurant*) shmat(id_cs, NULL, 0);


  sem_init(closeRestaurant, 1, 1); //1 means semaphore is used for process synchronization
  sem_init(eatMeal, 1, 0);
  sem_init(mutex,1,1);
  sem_init(&restaurant->closure,1,0);
 
 printf("check");

   restaurant[0].mealTime=atoi(argv[1]);
   restaurant[0].totalTables = argc-2;
   for(int i=0;i<restaurant[0].totalTables;i++)
     {
     restaurant[0].tables[i].capacity = atoi(argv[i+2]);
     restaurant[0].tables[i].available = true;
     restaurant[0].tables[i].tableNo = i;
     }
   restaurant[0].noOfGroups = 0;
   restaurant[0].noOfPeopleServed =0;
 

sem_wait(&restaurant->closure);


 for(int i=0;i<restaurant->totalTables;i++)
 { 
   sem_post(&restaurant->tables[i].waitForAll);
 }

 struct timespec ts;

                  if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
                {
                  /* handle error */
                  return -1;
                }

                  ts.tv_sec += restaurant->mealTime/1000;
                  sem_timedwait(eatMeal, &ts);
 
 printf("%d Guests served in %d Groups",restaurant->noOfPeopleServed,restaurant->noOfGroups);

  sem_destroy(closeRestaurant);
   sem_destroy(eatMeal);
   sem_destroy(mutex);
  shmdt(closeRestaurant);
  shmdt(eatMeal);
  shmdt(mutex);
  shmdt(restaurant);
  shmctl(id_sem, IPC_RMID, NULL);
  shmctl(id_sem1, IPC_RMID, NULL);
  shmctl(id_sem2, IPC_RMID, NULL);
  shmctl(id_cs, IPC_RMID, NULL);
}
