#include <stdio.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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
int main(int argv,char*argc[])
{


   struct Restaurant *restaurant;

  int id_sem=shmget(1250, 1024, 0);
  int id_sem1=shmget(1251, 1024, 0);
  int id_sem2=shmget(1252, 1024, 0);
  int id_cs= shmget(1253, sizeof(struct Restaurant),  0);

  sem_t *closeRestaurant;
  sem_t *eatMeal;
  sem_t *mutex;
  
 
  if (id_sem==-1 || id_cs==-1|| id_sem1==-1 ||id_sem2 ==-1)
  {
   
    printf("ERROR!");
    return 1;
    
  }


  closeRestaurant= (sem_t*) shmat(id_sem, NULL, 0);
  eatMeal = (sem_t*) shmat(id_sem1, NULL, 0);
  mutex = (sem_t*) shmat(id_sem2, NULL, 0);
  restaurant= (struct Restaurant*) shmat(id_cs, NULL, 0);


sem_wait(mutex);
 for(int i=0;i<restaurant->totalTables;i++)
 {
     printf("Table %d:",i);
     for(int j=0;j<=restaurant->tables[i].noOfGuests;j++)
     printf("%s ",restaurant->tables[i].guests[j].customerName);
     printf("\n");
 }

 for(int i=0;i<restaurant->noOfGroups;i++)
 {
     printf("Group %d:",i);
     for(int j=0;j<6;j++)
     printf("%s ",restaurant->reminderBook[i][j]);
     printf("\n");
 }

sem_post(mutex);

 printf("\n\n");




  shmdt(closeRestaurant);
  shmdt(eatMeal);
  shmdt(mutex);
  shmdt(restaurant);

}
