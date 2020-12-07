

#include "userInterface.h"


void Menu(struct Data* head)
{


	bool flag = true;
	int input;



	while (flag)
	{
		printf("1-View Report For Graduate Percentage of Each Country\n2-View Report For top 5 and bottom 5 countries for percentage of female graduates\n3-View Report For the graduate percentage for each country, by year from 2014 to 2017\n4-View Report For Detail On A Specific Country-\n5-View Report For Top 5 Countries for Most Number Of Doctorates\n6-Quit\n\n");
		scanf("%d", &input);
		system("clear");
                printf("Press any key to continue\n");
		getchar();

		if (input == 1)
		{
			generateReport1(head);
			printf("Press any key to continue\n");
			getchar();
			system("clear");

		}
		else if (input == 2)
		{
			generateReport2(head);
			printf("Press any key to continue\n");
			getchar();
			system("clear");

		}
		else if (input == 3)
		{
			generateReport3(head);
			printf("Press any key to continue\n");
			getchar();
			system("clear");

		}
		else if (input == 4)
		{
			generateReport4(head);
			printf("Press any key to continue\n");
			getchar();
			system("clear");

		}
		else if (input == 5)
		{
			generateReport5(head);
			printf("Press any key to continue\n");
			getchar();
			system("clear");

		}
		else if (input == 6)
		{
			flag = false;
		}
		else
		{
			printf("Incorrect Input. Kindly Try Again\n.");
			printf("Press any key to continue\n");
			getchar();

		}
	}
}

void Driver()
{
	struct Data* head = NULL;

	readDataFromFile(&head);
	Menu(head);

       struct Data*ptr = head;
       while(ptr!=NULL)
             {
                struct Data*next = ptr->next;
			free(ptr);
                       ptr = next;
	     }
}

