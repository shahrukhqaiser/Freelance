#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>

char* getStringFromBuffer(char* buffer)
{
	char* temp = nullptr;
	if (buffer != nullptr)
	{
		temp = new char[strlen(buffer) + 1];
		strcpy_s(temp, strlen(buffer) + 1, buffer);
	}

	return temp;
}

class QuestionType
{
	char* description;
	char* answer;
public:

	QuestionType()
	{
		description = nullptr;
		answer = nullptr;
	}

	void setDescription(char*_description)
	{
		description =getStringFromBuffer(_description);
	}

	char* getDescription()
	{
		return description;
	}

	void setAnswer(char* _answer)
	{
		answer = getStringFromBuffer(_answer);
	}

	char* getAnswer()
	{
		return answer;
	}
	
	virtual void  setOption1(char* buffer) {};
	virtual void  setOption2(char* buffer) {};
	virtual void  setOption3(char* buffer) {};
	virtual void  setOption4(char* buffer) {};

	virtual char* getOption1() 
	{
		char* temp = nullptr;
		return temp;
	};

	virtual char* getOption2() 
	{
		char* temp= nullptr;
		return temp;
	};

	virtual char* getOption3() 
	{
		char* temp = nullptr;
		return temp;
	};

	virtual char* getOption4() 
	{
		char* temp = nullptr;
		return temp;
	};

	virtual ~QuestionType()
	{
		if (description != nullptr)
		{
			delete[]description;
			description = nullptr;
		}

		if (answer != nullptr)
		{
			delete[]answer;
			answer = nullptr;
		}
	}
};

class MCQ: public QuestionType
{
	char* option1;
	char* option2;
	char* option3;
	char* option4;

public:

	MCQ()
	{
		option1 = option2 = option3 = option4 = nullptr;
	}
	
	char* getOption1()
	{
		return option1;
	}

	void setOption1(char*_option1)
	{
		option1 = getStringFromBuffer(_option1);
	}

	char* getOption2()
	{
		return option2;
	}

	void setOption2(char* _option2)
	{
		option2 = getStringFromBuffer(_option2);
	}

	char* getOption3()
	{
		return option3;
	}

	void setOption3(char* _option3)
	{
		option3 = getStringFromBuffer(_option3);
	}

	char* getOption4()
	{
		return option4;
	}

	void setOption4(char* _option4)
	{
		option4 = getStringFromBuffer(_option4);
	}
	
	~MCQ()
	{
		if (option1 != nullptr)
		{
			delete[]option1;
			option1 = nullptr;
		}
		if (option2 != nullptr)
		{
			delete[]option2;
			option2 = nullptr;
		}
		if (option3!= nullptr)
		{
			delete[]option3;
			option3 = nullptr;
		}
		if (option4 != nullptr)
		{
			delete[]option4;
			option4 = nullptr;
		}
	}
};

class FillInTheBlank: public QuestionType
{
public:
	FillInTheBlank()
	{

	}
	
	~FillInTheBlank()
	{

	}
};

class TrueFalse: public QuestionType
{
public:
	TrueFalse()
	{

	}
	~TrueFalse()
	{

	}
};

class Exam
{
	QuestionType** exam;
	int totalQuestions;
	int noOfMCQs;
	int noOfFillInTheBlanks;
	int noOfTrueFalse;
	

public:

	Exam()
	{
		exam = nullptr;
		totalQuestions = noOfMCQs = noOfFillInTheBlanks = noOfTrueFalse = 0;
	}

	static Exam* createDataBase()
	{
		ifstream fin;
		char* buffer = new char[500];
		Exam *dataBase = new Exam;

		fin.open("mcqs.txt");
		if (fin.is_open())
		{
			fin >> dataBase->noOfMCQs;
			fin.close();
		}
		else
			cout << "Error. File not opened\n";


		fin.open("fillintheblanks.txt");
		if (fin.is_open())
		{
			fin.ignore();
			fin.ignore();
			fin.ignore();
			

			fin >> dataBase->noOfFillInTheBlanks;
			fin.close();
		}
		else
			cout << "Error. File not opened\n";

		

		fin.open("truefalse.txt");
		if (fin.is_open())
		{
			fin >> dataBase->noOfTrueFalse;
			fin.close();
		}
		else
			cout << "Error. File not opened\n";


		dataBase->totalQuestions = dataBase->noOfMCQs + dataBase->noOfFillInTheBlanks + dataBase->noOfTrueFalse;

		dataBase->exam = new QuestionType*[dataBase->totalQuestions];

			for (int i = 0; i < dataBase->noOfMCQs; i++)
			{
				dataBase->exam[i] = new MCQ;
			}
			for (int i = dataBase->noOfMCQs; i < dataBase->noOfMCQs + dataBase->noOfFillInTheBlanks; i++)
			{
				dataBase->exam[i] = new FillInTheBlank;
			}
			for (int i = dataBase->noOfMCQs + dataBase->noOfFillInTheBlanks; i < dataBase->totalQuestions; i++)
			{
				dataBase->exam[i] = new TrueFalse;
			}
		
		int count = 0;
		int i = 0;
	
		
		fin.open("mcqs.txt");
		if (fin.is_open())
		{
			fin >> count;
			fin.ignore();
			int j = 0;

			while (count != 0 &&!fin.eof())
			{
				fin.ignore();
				fin.ignore();
				if (j > 8)
				{
					fin.ignore();
				}
				fin.getline(buffer,500);
				
					
				dataBase->exam[i]->setDescription(buffer);

				fin.getline(buffer, 500);
				dataBase->exam[i]->setOption1(buffer);
				fin.getline(buffer, 500);
				dataBase->exam[i]->setOption2(buffer);
				fin.getline(buffer, 500);
				dataBase->exam[i]->setOption3(buffer);
				fin.getline(buffer, 500);
				dataBase->exam[i]->setOption4(buffer);

				fin.getline(buffer, 500);
				dataBase->exam[i]->setAnswer(buffer);
				
				count--;
				i++;
				j++;
			}
			
			fin.close();
		}
		else
			cout << "File not opened. Error\n";

		fin.open("fillintheblanks.txt");
		if (fin.is_open())
		{
			fin.ignore();
			fin.ignore();
			fin.ignore();

			fin >> count;

			fin.ignore();
			int j = 0;

			while (count != 0 && !fin.eof())
			{
				fin.ignore();
				fin.ignore();
				if (j > 8)
				{
					fin.ignore();
				}

				fin.getline(buffer, 500);
				dataBase->exam[i]->setDescription(buffer);

				fin.getline(buffer, 500);
				dataBase->exam[i]->setAnswer(buffer);

				count--;
				i++;
				j++;
			}
			fin.close();
		}
		else
			cout << "File not opened. Error\n";

		

		fin.open("truefalse.txt");
		if (fin.is_open())
		{
		
			fin >> count;

			fin.ignore();

			int j = 0;

			while (count != 0 && !fin.eof())
			{
				fin.ignore();
				fin.ignore();
				if (j > 8)
				{
					fin.ignore();
				}
				fin.getline(buffer, 500);
				dataBase->exam[i]->setDescription(buffer);

				fin.getline(buffer, 500);
				dataBase->exam[i]->setAnswer(buffer);

				count--;
				i++;
				j++;
			}
		}
		else
			cout << "File not opened. Error\n";

		return dataBase;
	}

	void createPaper()
	{
		Exam* Data = createDataBase();
		bool flag = false;
		while (flag != true)
		{
			cout << "Enter the total number of questions you want to be in the examination\n";
			cin >> totalQuestions;
			if (totalQuestions < 0)
			{
				cout << "Incorrect input. Total Questions can't be a negative number. Try again.\n\n";
			}
			if (totalQuestions > Data->totalQuestions)
			{
				cout << "Incorrect input. Total Questions can't be greater than total number of questions available in the DataBase. Try again.\n\n";
			}
			if (totalQuestions >= 0 && totalQuestions <= Data->totalQuestions)
			{
				flag = true;
			}
		}
		flag = false;
		while (flag != true)
		{
			cout << "Enter the number of MCQs\n";
			cin >> noOfMCQs;

			if (noOfMCQs < 0)
			{
				cout << "Incorrect input. Total  number of MCQs can't be a negative number. Try again.\n\n";
			}
			if (noOfMCQs > Data->noOfMCQs)
			{
				cout << "Incorrect input. Total number of MCQs can't be greater than total number of such questions available in the DataBase. Try again.\n\n";
			}
			if (noOfMCQs >= 0 && noOfMCQs <= Data->noOfMCQs)
			{
				flag = true;
			}
		}

		flag = false;

		while (flag != true)
		{
			cout << "Enter the number of Fill In The Blanks\n";
			cin >> noOfFillInTheBlanks;

			if (noOfFillInTheBlanks < 0)
			{
				cout << "Incorrect input. Total  number of Fill In The Blank Questions can't be a negative number. Try again.\n\n";
			}
			if (noOfFillInTheBlanks > Data->noOfFillInTheBlanks)
			{
				cout << "Incorrect input. Total number of Fill In The Blank Questions can't be greater than total number of such questions available in the DataBase. Try again.\n\n";
			}
			if (noOfFillInTheBlanks >= 0 && noOfFillInTheBlanks <= Data->noOfFillInTheBlanks)
			{
				flag = true;
			}
		}
		flag = false;

		while (flag != true)
		{
			cout << "Enter the number of True/False\n";
			cin >> noOfTrueFalse;

			if (noOfTrueFalse < 0)
			{
				cout << "Incorrect input. Total number of True False Questions can't be a negative number. Try again.\n\n";
			}
			if (noOfTrueFalse > Data->noOfTrueFalse)
			{
				cout << "Incorrect input. Total number of True False Questions can't be greater than total number of such questions available in the DataBase. Try again.\n\n";
			}
			if (noOfTrueFalse >= 0 && noOfTrueFalse <= Data->noOfTrueFalse)
			{
				flag = true;
			}
		}

		if (noOfMCQs + noOfFillInTheBlanks + noOfTrueFalse == totalQuestions)
		{
			if (totalQuestions == 0)
				exam = nullptr;
			else
			{
				exam = new QuestionType * [totalQuestions];

				for (int i = 0; i < noOfMCQs; i++)
				{
					exam[i] = new MCQ;
				}
				for (int i = noOfMCQs; i < noOfMCQs + noOfFillInTheBlanks; i++)
				{
					exam[i] = new FillInTheBlank;
				}
				for (int i = noOfMCQs + noOfFillInTheBlanks; i < totalQuestions; i++)
				{
					exam[i] = new TrueFalse;
				}

				ofstream fout;
				ofstream Fout;
				
				int i = 1;

				fout.open("paper.txt");
				Fout.open("key.txt");

				fout << "\t\t\t\t\t Objective Paper\n\n";
				fout << "Total Questions:"<<totalQuestions<<endl;

				fout << "Number of MCQs:\t" << noOfMCQs;
				fout << "\t\tNumber of Fill In The Blanks:\t" << noOfFillInTheBlanks;
				fout << "\t\tNumber of True False:\t" << noOfTrueFalse<<endl<<endl;
				
				fout << "\t\t\t\t\tMCQ Portion\n\n";
				Fout << "\t\t\t\t\tMCQ Portion\n\n";
				while (noOfMCQs != 0)
				{
					srand(time(NULL));
					int r = rand() % Data->noOfMCQs;
					int rtemp = r;
					bool flag = false;
					

						while (flag != true)
						{
							if (Data->exam[r] != nullptr)
							{
								flag = true;
								fout << i << "-";
								fout << Data->exam[r]->getDescription()<<endl;
								fout << Data->exam[r]->getOption1() << endl;
								fout << Data->exam[r]->getOption2() << endl;
								fout << Data->exam[r]->getOption3() << endl;
								fout << Data->exam[r]->getOption4() << endl;
								fout << endl;
								Fout << i << "-";
								Fout << Data->exam[r]->getAnswer()<<endl;
								delete Data->exam[r];
								Data->exam[r] = nullptr;
								noOfMCQs--;
								i++;
								
							}
							if (flag != true)
							{
								if (r < Data->noOfMCQs-1)
								{
									r++;
								}
								else
								{
									r = rtemp;
									while (flag != true)
									{
										if (flag != true)
										{
											r--;
										}

										if (Data->exam[r] != nullptr)
										{
											flag = true;
											fout << i << "-";
											fout << Data->exam[r]->getDescription()<<endl;
											fout << Data->exam[r]->getOption1()<<endl;
											fout << Data->exam[r]->getOption2() << endl;
											fout << Data->exam[r]->getOption3() << endl;
											fout << Data->exam[r]->getOption4() << endl;
											fout << endl;
											Fout << i << "-";
											Fout << Data->exam[r]->getAnswer()<<endl;
											delete Data->exam[r];
											Data->exam[r] = nullptr;
											noOfMCQs--;
											i++;
										}
										
									}
								}
							}
						}
					
				}

				i = 1;

				fout << endl << endl << endl;

				fout << "\t\t\t\t\tFill In The Blanks Portion\n\n";

				Fout << endl << endl << endl;

				Fout << "\t\t\t\t\tFill In The Blanks Portion\n\n";

				while (noOfFillInTheBlanks != 0)
				{
					srand(time(NULL));
					int r = (rand() % Data->noOfTrueFalse) + Data->noOfMCQs;
					int rtemp = r;
					bool flag = false;


					while (flag != true)
					{
						if (Data->exam[r] != nullptr)
						{
							flag = true;
							fout << i << "-";
							fout << Data->exam[r]->getDescription() << endl;
							fout << endl;
							Fout << i << "-";
							Fout << Data->exam[r]->getAnswer() << endl;
							delete Data->exam[r];
							Data->exam[r] = nullptr;
							noOfFillInTheBlanks--;
							i++;

						}
						if (flag != true)
						{
							if (r < Data->noOfFillInTheBlanks - 1 + Data->noOfMCQs)
							{
								r++;
							}
							else
							{
								r = rtemp;
								while (flag != true)
								{
									if (flag != true)
									{
										r--;
									}

									if (Data->exam[r] != nullptr)
									{
										flag = true;
										fout << i << "-";
										fout << Data->exam[r]->getDescription() << endl;
										fout << endl;
										Fout << i << "-";
										Fout << Data->exam[r]->getAnswer() << endl;
										delete Data->exam[r];
										Data->exam[r] = nullptr;
										noOfFillInTheBlanks--;
										i++;
									}

								}
							}
						}
					}

				}

				i = 1;

				fout << endl << endl << endl;

				fout << "\t\t\t\t\tTrue False Portion\n\n";

				Fout << endl << endl << endl;

				Fout << "\t\t\t\t\tTrue False Portion\n\n";

				while (noOfTrueFalse != 0)
				{
					srand(time(NULL));
					int r = rand() % Data->noOfTrueFalse + Data->noOfFillInTheBlanks + Data->noOfMCQs;
					int rtemp = r;
					bool flag = false;


					while (flag != true)
					{
						if (Data->exam[r] != nullptr)
						{
							flag = true;
							fout << i << "-";
							fout << Data->exam[r]->getDescription() << endl;
							fout << endl;
							Fout << i << "-";
							Fout << Data->exam[r]->getAnswer() << endl;
							delete Data->exam[r];
							Data->exam[r] = nullptr;
							noOfTrueFalse--;
							i++;

						}
						if (flag != true)
						{
							if (r < Data->totalQuestions-1)
							{
								r++;
							}
							else
							{
								r = rtemp;
								while (flag != true)
								{
									if (flag != true)
									{
										r--;
									}

									if (Data->exam[r] != nullptr)
									{
										flag = true;
										fout << i << "-";
										fout << Data->exam[r]->getDescription() << endl;
										fout << endl;
										Fout << i << "-";
										Fout << Data->exam[r]->getAnswer() << endl;
										delete Data->exam[r];
										Data->exam[r] = nullptr;
										noOfTrueFalse--;
										i++;
									}

								}
							}
						}
					}

				}
				
			}
			system("cls");
			cout << "Paper Generated Successfully. Check paper.txt to see the generated paper and key.txt for the answers\n\n";
		}
		else
		{
		cout << "Error, Paper not generated. The number of total questions asked and the sum of sub categories is not equal. Try Again";
			Exam::Exam();
		}

		if (Data != nullptr)
		{
			for (int i = 0; i < Data->totalQuestions; i++)
			{
				if (Data->exam[i] != nullptr)
				{
					delete Data->exam[i];
					Data->exam[i] = nullptr;
				}
			}

			delete[]Data->exam;
			Data->exam = nullptr;
		}

	}

	~Exam()
	{
		if (exam != nullptr)
		{
			for (int i = 0; i < totalQuestions; i++)
			{
				if (exam[i] != nullptr)
				{
					delete exam[i];
					exam[i] = nullptr;
				}
			}

			delete[]exam;
			exam = nullptr;
		}
	}

};
int main()
{
	Exam object;
	object.createPaper();
}