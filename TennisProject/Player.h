#pragma once
#define MAX_LIMIT 100
#include <iostream>
using namespace std;
struct Score
{
	int score[6];
};

struct Player
{
	char* name;
	int id;
	Score** scores;
	int totalGamesPlayed;
	int bookedMatches[MAX_LIMIT];
	int noOfMatchesBooked;
	bool fees;

public:
	Player(int id, char* name);
	int calculateScore(int hole, int numberOfStrokes);
	void bookMatch(int matchId);
	bool payFee();
	void updateDetails(char* name, int handicap);
	~Player();

};