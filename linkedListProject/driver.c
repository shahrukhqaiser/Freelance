#include "driver.h"

void driver()
{
	char* str = calloc(1000, sizeof(char));
	LISTptr list = calloc(1, sizeof(LIST));

	printf("Enter your desired string/s. Press enter without typing anything when you wish to stop\n");
	for (int i = 1; strcmp(str, "\n") != 0; i++) //Taking input till we encounter a blank line
	{
		fgets(str, 1000, stdin);

		if (strcmp(str, "\n") != 0)
		{
			str[strlen(str) - 1] = '\0';    //Adding null character at the end to truncate the unnecessary data


 
			if (list->head == 0)  //Checking if it's the first element being added
			{
				list->head = createnodeSentence(str, i); //Node created
				list->noOfSentences = 1;
			}
			else
			{
				SENTENCEptr temp = list->head;
				for (int j = 0; j < list->noOfSentences - 1; j++)
				{
					temp = temp->next;
				}
				temp->next = createnodeSentence(str, i); //Node created
				list->noOfSentences++;
			}
			printf("\nSentence added.Enter another sentence or leave empty and press Enter to quit\n\n");
		}
	}

	printf("Enter the word/s you wish to search for. Press enter without typing anything when you wish to stop\n");

	strcpy(str, "");

	while (strcmp(str, "\n") != 0)  //Taking input till we encounter a blank line
	{

		fgets(str, 1000, stdin);

		if (strcmp(str, "\n") != 0)
		{
			str[strlen(str) - 1] = '\0'; //Adding null character at the end to truncate the unnecessary data


			searchWord(list, str); 

			printf("\nEnter another word or leave empty and press Enter to quit\n\n");
		}
	}

	strcpy(str,""); //Resetting the string 

	printList(list);
	printf("Enter the line/s you wish to remove. Press enter without typing anything when you wish to stop\n");

	while (strcmp(str, "\n") != 0)  //Taking input till we encounter a blank line
	{

		fgets(str, 1000, stdin);

		if (strcmp(str, "\n") != 0)
		{
			str[strlen(str) - 1] = '\0'; //Adding null character at the end to truncate the unnecessary data

			deleteLine(list, atoi(str)); //Deleting
			printList(list); //Displaying the changes

			printf("\nEnter another line number or leave empty and press Enter to quit\n\n");
		}
	}
	
    free(str);  //freed str
	deletelinkedList(list); //freed list
}


