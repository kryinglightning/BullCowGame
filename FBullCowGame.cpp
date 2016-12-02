#pragma once

#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetValidWordLength() { return MyValidWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "cruise";

	MyMaxTries = MAX_TRIES;
	MyValidWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}



bool FBullCowGame::IsGameWon() const {
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {

	if (false) //if the guess isn't an isogram, return an error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) //if the guess isn't all lowercase, return an error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != MyValidWord.length()) //if the guess' length is wrong, return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else //otherwise return OK
	{
		return EGuessStatus::OK;
	}

}



//receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	//increment the turn number
	MyCurrentTry++;
	
	//set up a return structure
	FBullCowCount BullCowCount; 
	int32 HiddenWordLength = GetValidWordLength();
	//loop through all letters in the guess
	for (int32 GuessChar = 0; GuessChar < HiddenWordLength; GuessChar++)
	{
		// compare the letters against the hidden word
		for (int32 HWChar = 0; HWChar < HiddenWordLength; HWChar++)
		{
			if (MyValidWord[HWChar] == Guess[GuessChar])
			{
				if (GuessChar = HWChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	return BullCowCount;
}
