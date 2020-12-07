
#include "Player.h"


Player::Player(int id, char* name)
{
	this->id = id;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	scores = new Score * [MAX_LIMIT];
	noOfMatchesBooked = 0;
	totalGamesPlayed = 0;

	fees = false;
}

int Player::calculateScore(int game, int point)
{
	
	int points = point;

	if (game == 0)
		scores[totalGamesPlayed] = new Score(); //gives memory 

	scores[totalGamesPlayed]->score[game] = points;

	if (game == 5)
		totalGamesPlayed++; //complete data entered for game so increment the counter

	return points;
}
void Player::bookMatch(int matchId)
{
	bookedMatches[noOfMatchesBooked] = matchId; //match booked
	noOfMatchesBooked++;
}
bool Player::payFee()
{
	if (fees == false)
	{
		fees = true;
		return true;
	}
	return false;
}
void Player::updateDetails(char* name, int handicap)
{
	delete[]this->name; //old memory assigned is deleted

	this->name = new char[strlen(name) + 1]; //new memory given
	strcpy_s(this->name, strlen(name) + 1, name);
}
Player::~Player()
{
	if (name != nullptr)
	{
		delete[]name;
		name = nullptr;
	}

	if (scores != nullptr)
	{
		for (int i = 0; i < totalGamesPlayed; i++)
			delete scores[i]; //delete all the scores

		delete[]scores; //delete pointers as  well
		scores = nullptr;
	}
}
