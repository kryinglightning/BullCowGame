#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map

//to make syntax UE friendly
using FText = std::string;
using int32 = int;

//default constructor
FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetValidWordLength() { return MyValidWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, { 4,6 }, { 5,10 }, { 6,12 }, {7, 16} };
	return WordLengthToMaxTries[MyValidWord.length()];

}

void FBullCowGame::Reset() {
	MyValidWord = "plane"; //this MUST be an isogram

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	//TODO write functions to complete the check
	if (!IsIsogram(Guess)) //if the guess isn't an isogram, return an error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) //if the guess isn't all lowercase, return an error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != MyValidWord.length()) //if the guess' length is wrong, return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (Guess == "") {
		return EGuessStatus::No_Input;
	}
	else //otherwise return OK
	{
		return EGuessStatus::OK;
	}

}



//receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyValidWord.length(); // assuming same length as guess

											  // loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyValidWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) 	// for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) {// if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;// add the letter to the map
		}
	}

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word)
	{
		if (Letter != tolower(Letter)) { return false; }
	}
	return true;
}
