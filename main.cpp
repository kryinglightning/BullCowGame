/*
console executable that makes use of BullCowClass
acts as the view in MVC pattern, is responsible for all user interaction, for game logic see FBullCowGame class
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void SumTheGame();
FText GetValidGuess();
bool AskPlayAgain();

FBullCowGame BCGame; //instantiate a new game which we re-use across tries

//entry point for the application
int main() {
	bool bAskPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bAskPlayAgain = AskPlayAgain();
	} while (bAskPlayAgain);
	return 0; //exit the application
}

void PrintIntro() {
	//introduce the game
	std::cout << "\n\nWelcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetValidWordLength() << " letter isogram I'm thinking about?\n";
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	//loop asking for guesses while there are still turns and the game is NOT won
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
		std::cout << "You have " << BCGame.GetMaxTries() - BCGame.GetCurrentTry() << " turns left\n";
	};
		
	SumTheGame();

	return;
}

//loop continuily until the user gives the valid guess
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess:";
		std::getline(std::cin, Guess);


		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetValidWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Your word must be an isogram! \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Your word should be all lowercase!\n";
			break;
		case EGuessStatus::No_Input:
			std::cout << "Please enter a word.\n";
			break;
		default:
			break;
		};
	} while (Status != EGuessStatus::OK); //keep looping until there are no errors
	return Guess;
}

bool AskPlayAgain() {
	std::cout << "Do you want to play again with the same word? (y/n) \n";
	FText Response = "";
	std::getline(std::cin,Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void SumTheGame() {
	if (BCGame.IsGameWon())
	{
		std::cout << "\nCONGRATULATIONS! You won!\n";
	}
	else {
		std::cout << "You lost. Better luck next time\n";
	};
	return;
}

