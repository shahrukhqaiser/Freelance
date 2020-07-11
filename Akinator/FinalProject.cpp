#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FileWrite(string filetowrite,string line);
void FileRead(string filetoread, string filetowrite, string line, char answer, string search, string countersearch);
void ClearFile(string filetowrite);
void SearchandNarrow(string filetowrite, string line,char answer, string search, string countersearch);



int main()
{
	string line;
	char answer;


	cout << "                                          WHAT'S ON YOUR MIND\n\n";
	cout << "                                                             Designed by:Hira and Shahrukh \n\n";
	cout << "Welcome to the What's On Your Mind program. Get ready for your mind to be read.\n\n";
	cout << "INSTRUCTIONS : You have to think of any student or faculty member which belongs or is teaching 18th Batch CS-G section.\n";
	cout << "The program will ask a series of questions and will let you know about the person you thought about at the end.\n\n";
	cout << "Kindly, answer the questions with only Y or y which would mean yes and N or n which would mean no.\nWe hope you'll comply with the instructions.\n\nThankyou for reading this all.\n\n";
	cout << "Let's begin shall we? \n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";


	cout << "Is the person whom you are thinking about a student?\n";
	cout << "Answer: ";
	cin >> answer;
	string search = "Student";
	string countersearch = "Faculty";
	FileRead("database.txt", "narrow.txt", line, answer, search, countersearch);

	if (answer == 'N' || answer == 'n')
	{
		cout << "Is the person young?\n";
		cout << "Answer: ";
		cin >> answer;
		search = " ";
		countersearch = "Aged";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");

		cout << "Does the person observe Burqa?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "burqa";
		countersearch = "noBurqah";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");

		cout << "Is your character always saying 'is pe aap k 2 marks kaaton ga' in PF Lab?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Twomarks";
		countersearch = "nowtwo";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");

		cout << "Do you attend only one lecture of your character per week?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "oneweek";
		countersearch = "noeweek";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");


		cout << "Does the individual teach Islamic and Religious Studies?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Islam";
		countersearch = "notisd";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");

		cout << "Does your character teaches Physics?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Physics";
		countersearch = "nophy";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");

	}

    cout << "Is the person of male gender?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Male";
	countersearch = "Female";
    FileRead("narrow.txt", "narrow1.txt",line, answer, search, countersearch);
    ClearFile("narrow.txt");

	if (answer == 'y' || answer == 'Y')
	{
		cout << "Does he have a full beard ?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Beard";
		countersearch = "Clean";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");

		cout << "Is he a member of the FAST Football Team?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Football";
		countersearch = "nofoot";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");
	}
	else if (answer == 'N' || answer == 'n')
	{
		cout << "Does your character possess really straight hair?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Straighthair";
		countersearch = "notsthair";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");

		cout << "Is your character always covering her head with a scarf?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Scarf";
		countersearch = "noscarf";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");

		cout << "Is your character's hair always tied in a bun?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Bun";
		countersearch = "nobun";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");

		cout << "Does your character wear a hijab?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Hijab";
		countersearch = "nohijab";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");

	}
	cout << "Is the individual Hafiz-e-Quran?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "hafiz";
	countersearch = "nohaafiz";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Does the individual wear glasses?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Glasses";
	countersearch = "No glasses";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	

	cout << "Does the person you are thinking about have freckles or acne?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Freckles";
	countersearch = "Clear";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Does your character have a fair complexion\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Fair";
	countersearch = "Dark";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Is your character Fat?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Healthy";
	countersearch = "Smart";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Is this individual really tall?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Tall";
	countersearch = "Normal";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Is the person you're thinking about usually found in the last benches?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "lastbench";
	countersearch = "nobench";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Has this person studied from LGS?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "LGS";
	countersearch = "nolgs";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Is the person you thinking about under the threat of facing a DC?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "DC";
	countersearch = "nodc";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Did your character attend the Welcome Party?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "noWel";
	countersearch = "wel";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Does he live in a hostel?\n";
	cout << "Answer: ";
    cin  >> answer;
	search = "Hostel";
	countersearch = "No hostel";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");



	
		cout << "Is your character from Okara?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "Okara";
		countersearch = "nokara";
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");


		if (answer == 'n' || answer == 'N')
		{
			cout << "Is your character from Faisalabad?\n";
			cout << "Answer: ";
			cin >> answer;
			search = "Faisalabad";
			countersearch = "notfsd";
			FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
			ClearFile("narrow1.txt");

			if (answer == 'n' || answer == 'N')
			{
				cout << "Does this person belong to Karachi?\n";
				cout << "Answer: ";
				cin >> answer;
				search = "Karachi";
				countersearch = "nokch";
				FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
				ClearFile("narrow.txt");



				if (answer == 'n' || answer == 'N')
				{
					cout << "Is this individual from Khushab?\n";
					cout << "Answer: ";
					cin >> answer;
					search = "Khushab";
					countersearch = "notkhush";
					FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
					ClearFile("narrow1.txt");
				}
			}
		}
	

	cout << "Was this individual challenged to score 99% in PF Mid?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "nintynine";
	countersearch = "noninty";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");


	cout << "Is your character an F.Sc topper in your class?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Topper";
	countersearch = "notto";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");


	cout << "Is your character's name called first during attendence?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Attendence";
	countersearch = "noattend";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Does your character have a lot of grey hair?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Greyhair";
	countersearch = "notgrey";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");


	cout << "Does your character have curly hair?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Curlyhair";
	countersearch = "nocurly";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Is your character the tallest in the class?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Tallest";
	countersearch = "notall";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Has this person undergone surgery recently?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Surgery";
	countersearch = "Nsurg";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Has your character been coming on a wheelchair for the past two weeks?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Wheelchair";
	countersearch = "nowheel";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Does your character wear funky shirts sometimes?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Funkyshirts";
	countersearch = "nofunk";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Does your character wear braces?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Braces";
	countersearch = "nobraces";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");


	cout << "Do you see your character only in Islamiyat and Relgious Studies classes?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Onlyisl";
	countersearch = "nonlyisl";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");


	


	cout << "Has your character been found coming consistently late to the Calculus classes recently?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Latecalculus";
	countersearch = "notlatecal";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Is this individual famous for his ratta skills in the Physics class?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Physicsratta";
	countersearch = "noratta";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");

	cout << "Did your character give presentation on robotic surgeory in IICT presentation?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "surgery";
	countersearch = "robot";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	if (answer == 'Y' || answer == 'y')
	{
		cout << "Did this person gave the introduction of the presentation?\n";
		cout << "Answer: ";
		cin >> answer;
		search = "introduction";
		countersearch = "noIntroduction";
		FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
		ClearFile("narrow1.txt");
		FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
		ClearFile("narrow.txt");
	}
		
	cout << "Was this individual caught in plagiarism case in PF lab ?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Lab";
	countersearch = "nolab";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");


	cout << "Was the person you thinking about called Test Charge in Physics Class?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Testcharge";
	countersearch = "notcharge";
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	cout << "Does your character's brother study in the same class as your's?\n";
	cout << "Answer: ";
	cin >> answer;
	search = "Brother";
	countersearch = "nobro";
	FileRead("narrow1.txt", "narrow.txt", line, answer, search, countersearch);
	ClearFile("narrow1.txt");
	FileRead("narrow.txt", "narrow1.txt", line, answer, search, countersearch);
	ClearFile("narrow.txt");

	
	ClearFile("narrow.txt");
	ClearFile("narrow1.txt");

	cout << "Sorry. Couldn't find your character. Maybe you answered some questions incorrectly? Kindly, try again.\n\n";
	
	system("pause");
	return 0;
}

void FileWrite(string filetowrite, string line)
{
	ofstream write;
	write.open(filetowrite,ios::app );
	
	

		write << line<<endl;	
	write.close();
}

void FileRead(string filetoread, string filetowrite, string line,char answer, string search, string countersearch)
{  
	ifstream read;
	int numberoflines = 0;

	read.open(filetoread);
	if (read.is_open())
	{
		while (getline(read, line,'\n'))
		{
			
			SearchandNarrow(filetowrite,line,answer,search,countersearch);
			numberoflines++;
		}
		read.close();
	}

	if (numberoflines == 1)
	{



		read.open(filetoread);
		if (read.is_open())
		{
			getline(read, line, '.');
	     	cout << "The person you thought about is " << line << endl;
			read.close();
			ClearFile("narrow.txt");
			ClearFile("narrow1.txt");
			system("pause");
			exit(0);
		
		}
	}

	else if (numberoflines == 0)
	{
		cout << "Sorry. Couldn't find your character. Maybe you answered some questions incorrectly? Kindly, try again.\n\n";
		system("pause");
		exit(0);
	}
	
	
}

void SearchandNarrow(string filetowrite, string line, char answer, string search, string countersearch)
{
	
	if (answer == 'Y' || answer == 'y')
	{

		if (line.find(search) != string::npos)

		{
			FileWrite(filetowrite, line);
		}
	}
	
		
	
	else if (answer == 'N' || answer == 'n')
	{
		
		if (line.find(countersearch) != string::npos)
			FileWrite(filetowrite, line);
	}
	else
	{
		cout << "Incorrect input. Kindly follow the instructions given\n";
		system("pause");
		exit(0);
	}
	          
	
}

void ClearFile(string filetowrite)
{
   
	ofstream write;
	write.open(filetowrite, ios::trunc);	
}


