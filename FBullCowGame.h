/*
the game logic (no view code or direst user interaction), 
the game is a simple guess the word game
*/

#pragma once
#include <iostream>
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	No_Input,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetValidWordLength();
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); 


	FBullCowCount SubmitValidGuess(FString);

private:
	FString MyValidWord;
	int32 MyCurrentTry;
	int32 MyMaxTries; //see constructor for initialization
	bool bGameIsWon;
	int32 UserLengthChoice;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};
