#pragma once
#ifndef DIARY_ENTRY_H
#define DIARY_ENTRY_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

const int MONTH_DAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string MONTHS[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

class DiaryEntry {
public:
	// A diary entry with the specified date and memory (content) is created. 
	// If the parameter "memory" is empty, or the date is invalid, exception happens.
	DiaryEntry(int day, int month, int year, string memory) throw(invalid_argument);

	// The copy constructor of the class
	DiaryEntry(const DiaryEntry& memory);

	//The class destructor
	~DiaryEntry();

	// The diary entry is written into a file named by its date and ".txt" extension. 
	// The date of the file is written first and is separated by a newline character from its content.
	void saveToFile() const;

	// The object and the file associated with it (if exists) are cleared. The file still exists, but with no content.
	void clear();

	// If the input date is valid, the date of the object is set to the specified date. 
	// If the date is not valid, an exception is thrown.
	void setDate(int day, int month, int year) throw(invalid_argument);

	// The memory is not null, it is appended to the content of the object as well as to the file associated with the object if exists. 
	// The memory is expanded if required.
	void addToContent(const string& memory);

	// If the date is not valid, the message: "The date is not valid." is displayed on the screen. 
	// If the date is valid, but there is no file associated with this date available on the current folder, 
	// the method displays: "No memory recorded on DATE" on the screen. 
	// Otherwise, the content of the file, in the format shown in the sample run, is displayed on the screen.
	static void display(int day, int month, int year);

private:
	// Returns true if the input parameters show a valid date and returns false otherwise.
	static bool validateDate(int day, int month, int year);

	// Returns true if the file named by the date of the object and ".txt" extension exists and returns false otherwise.
	bool fileExists() const;

	// The date of the memory in the form of: month_name day, year (ex. DEC 9, 2020)
	string date;

	// A dynamically allocated C-String storing the memory of the diary entry.
	char* content;

	// The size of the array pointed by the attribute "content" (the number of characters plus the terminating NULL character)
	int size;
};

#endif
