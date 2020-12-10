#include "DiaryEntry.h"

DiaryEntry::DiaryEntry(int day, int month, int year, string memory)
{
	
	if(memory == "" || DiaryEntry::validateDate(day,month,year) == false)    //checking whether it's a valid date or not
	throw invalid_argument("Invalid Arguments");

	else
	{
		size =memory.size() + 1;
		content = new char[size];   //assigning memory
		strcpy_s(content, size, memory.c_str()); //copying the contents

		setDate(day, month, year); //setting date

	}

	
}

DiaryEntry::DiaryEntry(const DiaryEntry& memory)
{
	if (memory.size > 0) //checking if the object to be copied is not empty
	{
		size = memory.size;
		content = new char[size]; //assigning memory
		strcpy_s(content, size, memory.content); //copying contents
		date = memory.date;
	}
}

DiaryEntry::~DiaryEntry()
{
	if (content != nullptr)
	{
		delete[]content;   
		content = nullptr;
	}
}

void DiaryEntry::saveToFile() const
{
	ofstream fout;
	string filename = date + ".txt"; //creating filename
	fout.open(filename);

	fout << date<<endl;  //writing date to text file
	fout << content; //writing the content to the text file

	fout.close(); //closing the file
}


void DiaryEntry:: clear()
{
	if (fileExists())
	{
		string filename = date + ".txt"; //creating filename
		ofstream fout;
		fout.open(filename, ios::trunc); //opening the file in truncate mode
		fout.close(); //closing the file
	}

	if (content != nullptr)
	{
		delete[]content;     //deleting data
		content = nullptr;
	}
	size = 0;
	date = "";
	
}

void DiaryEntry::setDate(int day, int month, int year)
{
	if (DiaryEntry::validateDate(day, month, year))
	{
		date = MONTHS[month - 1] + " " + to_string(day) + "," + to_string(year); //creating date according to the given format
	}
	else
	{
		throw invalid_argument("Invalid date");   //throw exception
	}
}

void DiaryEntry::addToContent(const string& memory)
{
	char* temp = new char[size]; //assigning memory to temp
	strcpy_s(temp, size, content); //copying the original content data

	delete[]content;

	size = size + memory.size(); //the new size after concatenation
	content = new char[size ]; //assigning new memory
	strcpy_s(content, size-memory.size(), temp); //copying the original content back from temp
	strcat_s(content, size , memory.c_str()); //concatenating the new content

	saveToFile(); //saving the chagnes to the file as well
}

void DiaryEntry::display(int day, int month, int year)
{
	if (validateDate(day, month, year))
	{
		string filename  = MONTHS[month - 1] + " " + to_string(day) + "," + to_string(year) +".txt"; //creating filename
		
		ifstream fin;
		fin.open(filename);
		if (fin.is_open())
		{
			string data;
			getline(fin,data,'\n');

			cout << "Date of Memory:" << data<<endl; //printing the date
			cout << "Memory:\n";
			while (!fin.eof())
			{
				getline(fin, data, '\n'); //printing the rest of data till EOF is found
				cout << data << endl;
			}
		}
		else
			cout << "No memory recorded on DATE\n";
	}
	else
		cout << "Invalid date\n";
}
bool DiaryEntry::validateDate(int day, int month, int year)
{
	if(year>0 && year<=2020)
		if(month>0 &&  month <=12)
			if (day > 0 && day<=MONTH_DAYS[month-1])
			{
				
				return true;
			}

	return false;
				
}

bool DiaryEntry::fileExists() const
{
	ifstream fin;
	string filename = date + ".txt";
	fin.open(filename);
	if (fin.is_open())
	{
		return true;
	}

	return false;
}