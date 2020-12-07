
#include "nodeWord.h"

WORDptr createnodeWord(char* word, int position)
{
	WORDptr node = (WORDptr) calloc(1, sizeof(NODEWORD)); //memory allocated

	node->length = strlen(word) + 1;
	node->word = (char*)calloc(node->length, sizeof(char)); //memory allocated
	strcpy(node->word, word); //data copied
	node->position = position;
	node->next = NULL;

	return node;
}

void deletenodeWord(WORDptr node)
{
	free(node->word); //memory freed
}
