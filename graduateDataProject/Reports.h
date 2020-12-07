

#include "Data.h"
#ifndef REPORT
#define REPORT
struct countryData
{
	char* countryName;
	int noOfStudents;
};


/*This function is used to generate the report for Graduate Percentage of Each Country*/
void generateReport1(struct Data* head);
/*This function compares two objects of CountryData type and returns the greater one according to the Number of Students.
This function is then used in the qsort function used in generating Report2*/
int cmpfunc(const void* a, const void* b);
//View Report For top 5 and bottom 5 countries for percentage of female graduates
void generateReport2(struct Data* head);
//View Report For the graduate percentage for each country, by year from 2014 to 2017
void generateReport3(struct Data* head);
//View Report For Detail On A Specific Country
void generateReport4(struct Data* head);
//View Report For Top 5 Countries for Most Number Of Doctorates
void generateReport5(struct Data* head);
#endif
