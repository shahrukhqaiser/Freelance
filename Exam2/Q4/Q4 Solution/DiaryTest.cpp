#include <iostream>
#include <string>
#include "DiaryEntry.h"

using namespace std;



int main() {
	cout << "Enter three integers for the memory date: (day month year) ";
	int d, m, y;
	cin >> d >> m >> y;
	cout << "What is the memory? Press the Tab key to terminate." << endl;
	string mem;
	getline(cin, mem, '\t');
	try {
		DiaryEntry memory(d, m, y, mem);
		memory.saveToFile();

		DiaryEntry::display(d, m, y);
		cout << endl;
		DiaryEntry::display(1, 1, 1970);
		cout << endl << "Cntent was added to the memory!" << endl;
		memory.addToContent(" And, I had a great time!");
		memory.display(d, m, y);
		memory.clear();
		cout << endl << "The memory was cleared!" << endl;
		memory.display(d, m, y);
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	return 0;
}