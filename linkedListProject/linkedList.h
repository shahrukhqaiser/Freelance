#include"nodeSentence.h"

#ifndef LINKEDLIST
#define LINKEDLIST

struct linkedList
{
	struct nodeSentence* head;
	int noOfSentences;
};

typedef struct linkedList LIST;
typedef LIST *LISTptr;

void searchWord(LISTptr, char* search);
void deletelinkedList(LISTptr);
void deleteLine(LISTptr, int lineNum);
void printList(LISTptr);

#endif