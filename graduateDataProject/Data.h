
#ifndef DATA
#define DATA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LIMIT 10000
#define COUNTRY_LIMIT 195


struct Data
{
	char* countryCode;
	char* countryName;
	char* degreeType;
	char gender;
	int year;
	int totalNoOfGraduates;
	struct Data* next;
};

/*This function is used to allocate memory to a Data type object by the use of double pointer
so that we can access the actual variable and assign memory to it*/
void allocateMemory(struct Data** inputoutput_data);
/*This function is used to initialize Data type Object*/
void initializeData(struct Data* node, char* countryCode, char* countryName, char gender, char* degreeType, int year, int totalNoOfGraduates);
/*This adds an element of Data type at the end of the linked List*/
void addElement(struct Data** head, struct Data* node);
/*This function reads all the data from file and stores it in the linkedList of Data type*/
void readDataFromFile(struct Data** head);

#endif
