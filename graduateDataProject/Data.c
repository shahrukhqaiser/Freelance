#include "Data.h"


void allocateMemory(struct Data** inputoutput_data)
{
	(*inputoutput_data) = calloc(1, sizeof(struct Data));
}

void initializeData(struct Data* node, char* countryCode, char* countryName, char gender, char* degreeType, int year, int totalNoOfGraduates)
{
	node->countryCode = calloc(strlen(countryCode) + 1, sizeof(char));
	strcpy(node->countryCode, countryCode);

	node->countryName = calloc(strlen(countryName) + 1, sizeof(char));
	strcpy(node->countryName, countryName);

	node->gender = gender;

	node->degreeType = calloc(strlen(degreeType) + 1, sizeof(char));
	strcpy(node->degreeType, degreeType);

	node->year = year;
	node->totalNoOfGraduates = totalNoOfGraduates;

}
void addElement(struct Data** head, struct Data* node)
{
	struct Data* ptr = *head;

	if (*head != NULL)
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = node;
		node->next = NULL;
	}

	else
	{
		*head = node;
		(*head)->next = NULL;
	}
}

void readDataFromFile(struct Data** head)
{
	FILE* fptr;
	if ((fptr = fopen("grad.dat", "r")) == NULL)
	{
		printf("Error! opening file");
		return;
	}
	else
	{
		char* countryCode = calloc(20, sizeof(char));
		char* countryName = calloc(50, sizeof(char));
		char gender;
		char* degreeType = calloc(5, sizeof(char));
		int year;
		int totalNoOfGraduates;


		while (fscanf(fptr, "%s %s %c %s %d %d", countryCode, countryName, &gender, degreeType, &year, &totalNoOfGraduates) != EOF)
		{
			struct Data* node;
			allocateMemory(&node);
			initializeData(node, countryCode, countryName, gender, degreeType, year, totalNoOfGraduates);

			addElement(&(*head), node);
		}
            free(countryCode);
	    free(countryName);
	    free(degreeType);

	}
}


