#pragma once
#include "Tennis.h"
#include <fstream>


	Tennis::Tennis()
	{
		players = new Player * [MAX_LIMIT];
		totalPlayers = 0;
		currentPlayer = nullptr;
	}
	void Tennis::addNewPlayer(char* name)
	{
		players[totalPlayers] = new Player(totalPlayers, name); //parameterized constructor called for Player
		currentPlayer = players[totalPlayers];
		totalPlayers++;
	}
	bool Tennis::removePlayer(int id)
	{
		if (id < totalPlayers && id >= 0)
			if (players[id] != nullptr)
			{
				delete players[id];   //Destructor for Player would be called
				players[id] = nullptr;
				return true;
			}

		return false;
	}
	bool Tennis::setCurrentPlayer(int id)
	{
		if (id < totalPlayers && id >= 0)
		{

			if (players[id] != nullptr)
			{
				currentPlayer = players[id];
				return true;
			}
		}

		return false;
	}
	void Tennis::enterScores(int hole, int numberOfStrokes)
	{
		currentPlayer->calculateScore(hole, numberOfStrokes);
	}
	void Tennis::printLatestScore()
	{
		if (currentPlayer->totalGamesPlayed != 0)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << "Game " << i + 1 << ": " << currentPlayer->scores[currentPlayer->totalGamesPlayed - 1]->score[i] << endl; //print score
			}
			cout << "\nThe match ID is:" << currentPlayer->totalGamesPlayed - 1 << endl << endl;
		}
		else
			cout << "You have not entered any scores yet\n";
	}
	void Tennis::printPreviousGameScore(int matchID)
	{
		if (matchID < currentPlayer->totalGamesPlayed && matchID >= 0)
		{
			for (int i = 0; i < 6; i++)
			{
				cout << "game " << i << ": " << currentPlayer->scores[matchID]->score[i] << endl; //print score
			}

			cout << "\nThe match ID is:" << matchID << endl << endl;
		}
		else
			cout << "Sorry, no match details found\n";
	}
	void Tennis::PlayerMenu()
	{
		int input;
		bool flag = true;

		system("pause");
		system("cls");

		cout << "Enter your playerID\n";
		cin >> input;

		

		if (setCurrentPlayer(input) == true)
		{
			while (flag == true)
			{

				system("pause");
				system("cls");

				cout << "1-Enter Scores\n2-View Latest Scores\n3-View Previous Scores\n4-Update Details\n5-Book Match\n6-Pay Fees\n7-Go To Previous Screen\n";
				cin >> input;
				if (input == 1)
				{
					system("pause");
					system("cls");
					cout << "Enter your points for:\n";
					for (int i = 0; i <6; i++)
					{
						cout << "Game " << i + 1 << ":";
						cin >> input;
						currentPlayer->calculateScore(i, input);
					}
				}

				else if (input == 2)
				{
					system("pause");
					system("cls");

					printLatestScore();
				}

				else if (input == 3)
				{
					system("pause");
					system("cls");

					cout << "Enter match ID for which you want to view your scores\n";
					cin >> input;
					printPreviousGameScore(input);
				}

				else if (input == 4)
				{
					char name[30];
					cout << "Enter your updated name\n";
					cin.ignore();
					cin.getline(name, 30);

					int handicap;
					cout << "Enter your updated handicap\n";
					cin >> handicap;
					currentPlayer->updateDetails(name, handicap);
				}
				else if (input == 5)
				{
					system("pause");
					system("cls");

					cout << "Enter the match ID for booking\n";
					cin >> input;
					currentPlayer->bookMatch(input);

					cout << "Match successfully booked\n";
				}

				else if (input == 6)
				{
					system("pause");
					system("cls");
					if (currentPlayer->payFee() == true)
						cout << "Fees paid successfully\n";
					else
						cout << "You've already paid your fees\n";
				}
				else if (input == 7)
				{
					system("pause");
					system("cls");
					flag = false;
				}
				else
				{
					system("pause");
					system("cls");

					cout << "Incorrect input. Try again\n";
				}
			}
		}

		else
		{
			system("pause");
			system("cls");

			cout << "No member with this id exists. Kindly try again\n\n";
		}


	}
	void Tennis::managementMenu()
	{
		int input;
		bool flag = true;

		while (flag == true)
		{
			system("pause");
			system("cls");
			cout << "\n\n1-Add Player\n2-Remove Player\n3-Check Overdue Fees\n4-Quit\n\n";
			cin >> input;


			if (input == 1)
			{
				system("pause");
				system("cls");
				char name[30];
				int handicap;
				cout << "Enter name\n";

				cin.ignore();
				cin.getline(name, 30);

				addNewPlayer(name);

				cout << "\nPlayer successfully added\n\n";
				cout << "The ID is " << players[totalPlayers - 1]->id << endl;
			}
			else if (input == 2)
			{
				system("pause");
				system("cls");
				int id;
				cout << "Enter player ID\n";
				cin >> id;

				if (removePlayer(id) == true)
				{

					cout << "Player successfully removed\n";
				}

				else
				{
					cout << "No Player exists with this ID\n";
				}
			}

			else if (input == 3)
			{
				system("pause");
				system("cls");
				int id;
				cout << "Enter player ID\n";
				cin >> id;

				if (id < totalPlayers && id >= 0)
				{
					if (players[id] != nullptr)
					{
						if (players[id]->fees)
						{
							cout << "No overdue fees\n";

						}
						else
							cout << "Fees overdue\n";
					}
					else
						cout << "No player exists with this ID\n";
				}
				else
					cout << "No player exists with this ID\n";
			}
			else if (input == 4)
			{
				system("cls");
				system("pause");

				flag = false;
			}
			else
			{
				system("pause");
				system("cls");
				cout << "Incorrect input. Try again\n\n";
			}
		}
	}
	void Tennis::Menu()
	{
		cout << "Welcome to Sports Club Tennis Management Application.\n";

		int input;
		bool flag = true;

		while (flag)
		{
			cout << "\n1-Player Menu\n2-Management Menu\n3-Quit\n\n";
			cin >> input;

			if (input == 1)
			{

				PlayerMenu();

			}
			else if (input == 2)
			{
				managementMenu();
			}
			else if (input == 3)
			{
				system("cls");
				system("pause");
				flag = false;
			}
			else
			{
				system("pause");
				system("cls");
				cout << "Incorrect input. Try again\n";
			}
		}
	}
	void Tennis::storeDataInFile() //store data in file
	{
		ofstream fout;
		fout.open("Data.txt");
		ofstream fout2;
		fout2.open("Scores.txt");

		int matchID = 0;
		for (int i = 0; i < totalPlayers; i++)
		{

			if (players[i] != nullptr)
			{
				fout << players[i]->id << ";" << players[i]->name << ";" << players[i]->totalGamesPlayed << "\n"; //store player details

				for (int j = 0; j < players[i]->totalGamesPlayed; j++)
				{
					fout2 << matchID << ";";
					for (int k = 0; k < 6; k++)
						fout2 << players[i]->scores[j]->score[k] << " "; //store all scores

					fout2 << "\n";
					matchID++;
				}
			}
		}

		fout.close(); //close file
		fout2.close(); //close file
	}
	Tennis::~Tennis()
	{
		if (players != nullptr)
		{
			for (int i = 0; i < totalPlayers; i++)
			{
				delete players[i]; //destructor for player called
			}

			delete[]players; 

			players = nullptr;
		}
	}
