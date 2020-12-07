#include "linkedList.h"


void searchWord(LISTptr list, char* search)
{
	SENTENCEptr sentence = list->head;
	bool flag = false;

	for (int i = 0; i < list->noOfSentences; i++)   //Searching in all the Sentences
	{
		WORDptr Word = sentence->head; //Setting te head

		for (int j = 0; j < sentence->noOfWords; j++) //Going through all the words
		{
			if (strcmp(search, Word->word) == 0)
			{
				flag = true;
				printf("The word %s has been found at line number %d and position %d\n", search, sentence->lineNumber, Word->position); //Word found
			}

			Word = Word->next; //Moving on to the next word
		}

		sentence = sentence->next; //Moving on to the next sentence
	}

	if (!flag)
	{
		printf("Could not find the word in the text\n");
	}
}


void deletelinkedList(LISTptr list)
{
	SENTENCEptr current;
	SENTENCEptr Next;

	if (list->head != NULL)
	{
		current = list->head;
		Next = list->head->next;
		for (int i = 0; i < list->noOfSentences - 1; i++)
		{
			deletenodeSentence(current);   //func called to free memory
			free(current); //memory freed
			current = Next;
			Next = Next->next;
		}
	}
}
void deleteLine(LISTptr list, int lineNum)
{
	if (lineNum > list->noOfSentences)
	{
		printf("This line does not exist in the text\n");
	}
	else
	{
		if (lineNum == 1)  //case if first elements needs to be removed
		{
			SENTENCEptr temp = NULL;
			temp = list->head->next;
			deletenodeSentence(list->head);
			free(list->head);
			list->head = temp;
			list->noOfSentences--;

			for (int i = 0; i < list->noOfSentences; i++)
			{
				temp->lineNumber--;
				temp = temp->next;
			}
		}
		else if (lineNum == list->noOfSentences) //case if last element needs to be removed
		{
			SENTENCEptr temp = NULL;
			temp = list->head;

			for (int i = 1; i < lineNum; i++)
			{
				temp = temp->next;
			}
			deletenodeSentence(temp);
			free(temp);
			list->noOfSentences--;
		}

		else   // case for rest of the elements
		{
			SENTENCEptr temp = NULL;
			SENTENCEptr temp1 = NULL;
			temp = list->head;

			for (int i = 1; i < lineNum - 1; i++)
			{
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = temp->next->next;
			deletenodeSentence(temp1);
			free(temp1);

			temp = temp->next;
			for (int i = lineNum; i < list->noOfSentences; i++)
			{
				temp->lineNumber--;
				temp = temp->next;
			}
			list->noOfSentences--;
		}
	}
}

void printList(LISTptr list)
{
	SENTENCEptr temp = list->head;

	for (int i = 0; i < list->noOfSentences; i++) //Traversing through the entire list
	{
		printf("%d: ", temp->lineNumber);
		printSentence(temp);
		printf("\n");
		temp = temp->next;
	}
}
