#include "nodeWord.h"

#ifndef SENTENCE
#define SENTENCE

struct nodeSentence
{
struct nodeWord* head;
int lineNumber;
int noOfWords;
struct nodeSentence* next;
};

typedef struct nodeSentence NODESENTENCE;
typedef NODESENTENCE *SENTENCEptr;

SENTENCEptr createnodeSentence(char* sentence, int lineNumber);
void printSentence(SENTENCEptr ptr);
void deletenodeSentence(SENTENCEptr node);
#endif
