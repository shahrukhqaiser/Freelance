#ifndef WORD
#define WORD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct nodeWord
{
	char* word;
	int length;
	int position;
	struct nodeWord* next;

};

typedef struct nodeWord NODEWORD;
typedef NODEWORD* WORDptr;

WORDptr createnodeWord(char* word, int position);
void deletenodeWord(WORDptr node);

#endif
