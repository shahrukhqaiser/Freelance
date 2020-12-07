#include "Reports.h"

void generateReport1(struct Data* head)
{
	int underGrads = 0;
	int masterGrads = 0;
	int Doctorates = 0;
	int total = 0;

	int* countryUndergrad = calloc(MAX_LIMIT, sizeof(int));
	int* countryMastergrad = calloc(MAX_LIMIT, sizeof(int));
	int* countryDoctorates = calloc(MAX_LIMIT, sizeof(int));
	int* countryTotal = calloc(MAX_LIMIT, sizeof(int));

	if (head != NULL)
	{
		struct Data* ptr = head;
		char countryNames[COUNTRY_LIMIT][50];
		strcpy(countryNames[0], ptr->countryName);

		int i = 1;
		while (ptr != NULL)
		{
			if (strcmp(ptr->countryName, countryNames[i - 1]) != 0)
			{
				strcpy(countryNames[i], ptr->countryName);
				i++;
			}

			if (ptr->gender == 'T')
			{
				if ((strcmp(ptr->degreeType, "L6")) == 0)
				{

					underGrads += ptr->totalNoOfGraduates;
					countryUndergrad[i - 1] += ptr->totalNoOfGraduates;
				}
				else if ((strcmp(ptr->degreeType, "L7")) == 0)
				{

					masterGrads += ptr->totalNoOfGraduates;
					countryMastergrad[i - 1] += ptr->totalNoOfGraduates;
				}

				else if ((strcmp(ptr->degreeType, "L8")) == 0)
				{

					Doctorates += ptr->totalNoOfGraduates;
					countryDoctorates[i - 1] += ptr->totalNoOfGraduates;
				}

				countryTotal[i - 1] += ptr->totalNoOfGraduates;
				total += ptr->totalNoOfGraduates;
			}
			ptr = ptr->next;

		}

		printf("Country Name\t\t    Bachelor's\t     Master's\t\tDoctorate\tTotal\n");

		for (int j = 0; j < i; j++)
		{
			float bachelorPercentage = ((float)countryUndergrad[j] * 100 / (float)underGrads);
			float masterPercentage = ((float)countryMastergrad[j] * 100 / (float)masterGrads);
			float doctoratePercentage = ((float)countryDoctorates[j] * 100 / (float)Doctorates);
			float totalPercentage = ((float)countryTotal[j] * 100 / (float)total);

			printf("%-20s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f \n", countryNames[j], bachelorPercentage, masterPercentage, doctoratePercentage, totalPercentage);
		}


	}
free(countryUndergrad);
free(countryMastergrad);
free(countryDoctorates);
free(countryTotal);

}
int cmpfunc(const void* a, const void* b)
{

	return ((((struct countryData*)a)->noOfStudents) - (((struct countryData*)b)->noOfStudents));
}
void generateReport2(struct Data* head)
{



	int totalFemales = 0;


	struct countryData* Data = calloc(COUNTRY_LIMIT, sizeof(struct countryData));


	if (head != NULL)
	{
		struct Data* ptr = head;


		Data[0].countryName = calloc(strlen(ptr->countryName) + 1, sizeof(char));
		strcpy(Data[0].countryName, ptr->countryName);
		Data[0].noOfStudents = 0;

		int i = 1;
		while (ptr != NULL)
		{
			if (strcmp(ptr->countryName, Data[i - 1].countryName) != 0)
			{
				Data[i].countryName = calloc(strlen(ptr->countryName) + 1, sizeof(char));
				strcpy(Data[i].countryName, ptr->countryName);
				Data[i].noOfStudents = 0;
				i++;
			}

			if (ptr->gender == 'F')
			{

				Data[i - 1].noOfStudents += ptr->totalNoOfGraduates;
				totalFemales += ptr->totalNoOfGraduates;
			}


			ptr = ptr->next;
		}
		qsort(Data, i - 1, sizeof(struct countryData), cmpfunc);

		printf("Top 5 Countries for Female Graduates\n\n");
		printf("Country\t\t   Female Graduate Percentage\n\n");

		int j = i;
		for (int k = 0; k < 5; k++)
		{

			float countryPercentage = ((float)Data[j - 1].noOfStudents * 100 / (float)totalFemales);

			printf("%-20s\t\t%.2f\n", Data[j - 1].countryName, countryPercentage);
			j--;
		}

		printf("\nBottom 5 Countries for Female Graduates\n\n");
		printf("Country\t\t   Female Graduate Percentage\n\n");
		for (int i = 0; i < 5; i++)
		{

			float countryPercentage = ((float)Data[i].noOfStudents * 100 / (float)totalFemales);

			printf("%-20s\t\t%.2f\n", Data[i].countryName, countryPercentage);
		}




	}

free(Data);
}
void generateReport3(struct Data* head)
{

	int total[4];
	for (int i = 0; i < 4; i++)
		total[i] = 0;

	int countryTotal[COUNTRY_LIMIT][4];

	for (int i = 0; i < COUNTRY_LIMIT; i++)
		for (int j = 0; j < 4; j++)
			countryTotal[i][j] = 0;
	if (head != NULL)
	{
		struct Data* ptr = head;
		char countryNames[COUNTRY_LIMIT][50];
		strcpy(countryNames[0], ptr->countryName);

		int i = 1;
		while (ptr != NULL)
		{
			if (strcmp(ptr->countryName, countryNames[i - 1]) != 0)
			{
				strcpy(countryNames[i],ptr->countryName);
				i++;
			}

			if (ptr->gender == 'T')
			{
				if (ptr->year == 2014)
				{
					countryTotal[i - 1][0] += ptr->totalNoOfGraduates;

					total[0] += ptr->totalNoOfGraduates;
				}

				else if (ptr->year == 2015)
				{
					countryTotal[i - 1][1] += ptr->totalNoOfGraduates;

					total[1] += ptr->totalNoOfGraduates;
				}

				else if (ptr->year == 2016)
				{
					countryTotal[i - 1][2] += ptr->totalNoOfGraduates;

					total[2] += ptr->totalNoOfGraduates;
				}

				else if (ptr->year == 2017)
				{
					countryTotal[i - 1][3] += ptr->totalNoOfGraduates;

					total[3] += ptr->totalNoOfGraduates;
				}

			}
			ptr = ptr->next;

		}

		float year_2014 = 0;
		float year_2015 = 0;
		float year_2016 = 0;
		float year_2017 = 0;


		printf("Country Name\t\t\t2014\t\t2015\t\t2016\t\t2017\n\n");
		for (int j = 0; j < i - 1; j++)
		{
			year_2014 = ((float)countryTotal[j][0] * 100) / (float)total[0];
			year_2015 = ((float)countryTotal[j][1] * 100) / (float)total[1];
			year_2016 = ((float)countryTotal[j][2] * 100) / (float)total[2];
			year_2017 = ((float)countryTotal[j][3] * 100) / (float)total[3];
			printf("%-20s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", countryNames[j], year_2014, year_2015, year_2016, year_2017);
		}
	}


}
void generateReport4(struct Data* head)
{

	char countryName[50];
	while (getchar() != '\n');
	printf("Enter the name of the country for which you want to view the details\n");
	
	fgets(countryName, 50, stdin);
	countryName[strlen(countryName) - 1] = '\0';
	int underGrads = 0;
	int masterGrads = 0;
	int Doctorates = 0;
	int total = 0;


	if (head != NULL)
	{
		struct Data* ptr = head;




		while (ptr != NULL)
		{
			if (strcmp(ptr->countryName, countryName) == 0)
			{


				if (ptr->gender == 'T')
				{
					if ((strcmp(ptr->degreeType, "L6")) == 0)
					{

						underGrads += ptr->totalNoOfGraduates;
					}
					else if ((strcmp(ptr->degreeType, "L7")) == 0)
					{

						masterGrads += ptr->totalNoOfGraduates;

					}

					else if ((strcmp(ptr->degreeType, "L8")) == 0)
					{

						Doctorates += ptr->totalNoOfGraduates;

					}

					total += ptr->totalNoOfGraduates;
				}
			}
			ptr = ptr->next;

		}


		float bachelorPercentage = ((float)underGrads * 100 / (float)total);
		float masterPercentage = ((float)masterGrads * 100 / (float)total);
		float doctoratePercentage = ((float)Doctorates * 100 / (float)total);


		printf("Country Name:%s\n\nNumber of Bachleor's Graduates:%d\nPercentage:%.2f\n\nNumber of Master's Graduates:%d\nPercentage:%.2f\n\nNumber of Doctorates:%d\nPercentage:%.2f\n\n", countryName, underGrads, bachelorPercentage, masterGrads, masterPercentage, Doctorates, doctoratePercentage);

	}

}
void generateReport5(struct Data* head)
{
	struct countryData* Data = calloc(COUNTRY_LIMIT, sizeof(struct countryData));


	if (head != NULL)
	{
		struct Data* ptr = head;


		Data[0].countryName = calloc(strlen(ptr->countryName) + 1, sizeof(char));
		strcpy(Data[0].countryName, ptr->countryName);
		Data[0].noOfStudents = 0;

		int i = 1;
		while (ptr != NULL)
		{
			if (strcmp(ptr->countryName, Data[i - 1].countryName) != 0)
			{
				Data[i].countryName = calloc(strlen(ptr->countryName) + 1, sizeof(char));
				strcpy(Data[i].countryName, ptr->countryName);
				Data[i].noOfStudents = 0;
				i++;
			}

			if (ptr->gender == 'T')
			{
				if ((strcmp(ptr->degreeType, "L8") == 0))
				{

					Data[i - 1].noOfStudents += ptr->totalNoOfGraduates;

				}
			}

			ptr = ptr->next;

		}
		qsort(Data, i - 1, sizeof(struct countryData), cmpfunc);

		printf("Top 5 Countries for most number of Doctorates are:\n\n");
		printf("Country\t\t   Number of Doctorates\n\n");

		int j = i;
		for (int k = 0; k < 5; k++)
		{
			printf("%-20s\t\t%d\n", Data[j - 1].countryName, Data[j - 1].noOfStudents);
			j--;
		}
	}

free(Data);

}

