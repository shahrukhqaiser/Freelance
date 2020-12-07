#include "nodeSentence.h"

SENTENCEptr createnodeSentence(char* sentence, int lineNumber)
{
	 SENTENCEptr node = (SENTENCEptr) calloc(1, sizeof(NODESENTENCE));
	 WORDptr ptr = (WORDptr) calloc(1, sizeof(NODEWORD));


	int count = 0;
	int position = 0;
	int i = 0;
	int j = 0;

	while (i < strlen(sentence))                //extracting words from sentence
	{
		for (i; sentence[i] != ' ' && i < strlen(sentence); i++)
		{
			count++;                                //calculating the size of the word
		}

		while (sentence[i] == ' ')
			i++;										//skipping the space/s

		char* word;
		word = calloc(count, sizeof(char));

		for (int k = 0; k < count; j++, k++)
		{
			word[k] = sentence[j];
		}
		word[count] = '\0';

		while (sentence[j] == ' ')
			j++;                                      //skipping the space/s

		if (position == 0)                        //Checking if it's first word
		{
			ptr = createnodeWord(word, position + 1);
		}
		else
		{
			WORDptr temp = ptr;

			for (int i = 0; i < position - 1; i++)
			{
				temp = temp->next; //finding the end of the linked list to add new node
			}
			temp->next = createnodeWord(word, position + 1); //using the createnodeWord function to create nodes of nodeWord type.
		}

		position++;
		count = 0;
	}


	node->head = ptr;
	node->lineNumber = lineNumber;
	node->noOfWords = position;
	node->next = NULL;

	return node;

}

void printSentence(SENTENCEptr ptr)
{
	WORDptr node = ptr->head;
	for (int i = 0; i < ptr->noOfWords; i++)  //Loop to keep printing till all words in the sentence have been displayed
	{
		printf("%s ", node->word);
		node = node->next;
	}
}

void deletenodeSentence(SENTENCEptr node)
{

	WORDptr current;
	WORDptr Next;

	current = node->head;    
	Next = node->head->next;     //Storing the next element in another pointer so we can accesss it later
	for (int i = 0; i < node->noOfWords - 1; i++)
	{
		deletenodeWord(current);    //func called to freememory
		free(current); //memory freed
		current = Next;
		Next = Next->next;
	}
}
