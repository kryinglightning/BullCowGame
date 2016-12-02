#pragma once
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

	void Reset(); // TODO make a rich return value

	FBullCowCount SubmitGuess(FString);

private:
	FString MyValidWord;
	int32 MyCurrentTry;
	int32 MyMaxTries; //see constructor for initialization

};
