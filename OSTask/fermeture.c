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
  int id_cs= shmget(1253, sizeof(struct Restaurant),  0);

  sem_t *closeRestaurant;
  sem_t *eatMeal;
  
 
  if (id_sem==-1 || id_cs==-1|| id_sem1==-1)
  {
   
    printf("ERROR!");
    return 1;
    
  }

  closeRestaurant= (sem_t*) shmat(id_sem, NULL, 0);
  eatMeal = (sem_t*) shmat(id_sem1, NULL, 0);
  restaurant= (struct Restaurant*) shmat(id_cs, NULL, 0);


 sem_wait(closeRestaurant);
 sem_post(&restaurant->closure);

  shmdt(closeRestaurant);
  shmdt(eatMeal);
  shmdt(restaurant);

}
