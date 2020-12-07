#pragma once
#include "Player.h"

struct Tennis
{
	Player** players;
	int totalPlayers;
	Player* currentPlayer;

	Tennis();
	void addNewPlayer(char* name);
	bool removePlayer(int id);
	bool setCurrentPlayer(int id);
	void enterScores(int game, int points);
	void printLatestScore();
	void printPreviousGameScore(int matchID);
	void PlayerMenu();
	void managementMenu();
	void Menu();
	void storeDataInFile();
	~Tennis();
};