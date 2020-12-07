#include <stdio.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
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


int getTable(struct Restaurant* restaurant, int noOfPeople)
{
   int table = -1;
   int tableNum = -1;
  for(int i =0;i<restaurant->totalTables;i++)
     {
       if(restaurant->tables[i].capacity>table && restaurant->tables[i].capacity>=noOfPeople &&restaurant->tables[i].available ==true )
       {
             table = restaurant->tables[i].capacity;
             tableNum =restaurant->tables[i].tableNo;

       }
	else if(restaurant->tables[i].capacity<table && restaurant->tables[i].capacity>=noOfPeople&&restaurant->tables[i].available ==true )
           {
		table = restaurant->tables[i].capacity;
                tableNum =restaurant->tables[i].tableNo;
           }
     }
     
   if(tableNum!=-1)
      {
          restaurant->tables[tableNum].available = false;
          restaurant->tables[tableNum].noOfTotalGuests = noOfPeople;
          sem_init(&restaurant->tables[tableNum].waitForAll,1,0); 
      }
      return tableNum;
    
}

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


char name[10];
if(strlen(argc[1])<=10)
{
strcpy(name,argc[1]);
 
  sem_wait(mutex);
 int rc =sem_trywait(closeRestaurant);
if ((rc == -1) && (errno == EAGAIN)) 
{
   printf("Sorry %s no table available\n",name);
   sem_post(mutex);
}

else
{
  sem_post(closeRestaurant);
if(argc[2][0] >='0' && argc[2][0] <= '9')
{
   int noOfPeople = atoi(argc[2]);
   int tableNo = getTable(restaurant,noOfPeople);
    
   if(tableNo!=-1)
    {
       strcpy(restaurant->tables[tableNo].guests[0].customerName,name); 
       strcpy(restaurant->reminderBook[restaurant->noOfGroups][0],name);
       restaurant->noOfPeopleServed++;

        restaurant->tables[tableNo].noOfGuests = 0; 
        restaurant->noOfGroups++;
        
       printf("Welcome %s you have the table No %d\n",restaurant->tables[tableNo].guests[0].customerName,tableNo);
       sem_post(mutex);
       sem_wait(&restaurant->tables[tableNo].waitForAll);
       sem_post(&restaurant->tables[tableNo].waitForAll);
       
    }
   
   else
   {
     printf("Sorry %s no table available\n",name);
     sem_post(mutex);
   }
      
          
}

else
{
  char hostName[10];
  bool flag = false;
  strcpy(hostName,argc[2]);
  for(int i=0;i<restaurant->totalTables &&flag == false;i++)
     {
        if(strcmp(restaurant->tables[i].guests[0].customerName,hostName) ==0)
         {
          restaurant->tables[i].noOfGuests++;
          restaurant->noOfPeopleServed++;

           strcpy(restaurant->tables[i].guests[restaurant->tables[i].noOfGuests].customerName,name);
           for(int j =0;j<restaurant->noOfGroups;j++)
           {
            if(strcmp(restaurant->reminderBook[j][0],hostName)==0)
           strcpy(restaurant->reminderBook[j][restaurant->tables[i].noOfGuests],name); 
           }

           flag = true;

            printf("Welcome %s you have the table No %d\n",restaurant->tables[i].guests[restaurant->tables[i].noOfGuests].customerName,restaurant->tables[i].tableNo);

            if(restaurant->tables[i].noOfTotalGuests-1 == restaurant->tables[i].noOfGuests)
            {
              printf("All the guests of this table have arrived. You can start eating your meal\n\n");

              struct timespec ts;

                  if (clock_gettime(CLOCK_REALTIME, &ts) == -1)
                {
                  /* handle error */
                  return -1;
                }

                  ts.tv_sec += restaurant->mealTime/1000;
                  sem_post(mutex);
                  sem_timedwait(eatMeal, &ts);
              
              for(int j=0;j<restaurant->tables[i].noOfTotalGuests;j++)
              {
                   strcpy(restaurant->tables[i].guests[j].customerName," ");
              } 
              restaurant->tables[i].available = true;
              restaurant->tables[i].noOfGuests =0;
              restaurant->tables[i].noOfTotalGuests =0;
             
             sem_post(&restaurant->tables[i].waitForAll);

            }
            else
            { 
              sem_post(mutex);
              sem_wait(&restaurant->tables[i].waitForAll);
              sem_post(&restaurant->tables[i].waitForAll);
            }
            
            
         } 
     } 

 if(flag == false)
{
  printf("Sorry %s, no %s here\n",name,hostName);
  sem_post(mutex);
}


}
}
}
else
{
  printf("Enter name within 10 characters\n");
}


  shmdt(closeRestaurant);
  shmdt(eatMeal);
  shmdt(mutex);
  shmdt(restaurant);

}
