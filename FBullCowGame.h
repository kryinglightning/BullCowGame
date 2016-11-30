#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); //constructor
	int GetMaxTries() const;
	int GetAWordLength();
	std::string GetANewWord();
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a rich return value
	bool CheckGuessValidity(std::string); //TODO make a rich return value





private:
	int MyCurrentTry;
	int MyMaxTries; //see constructor for initialization
};
