/*
console executable that makes use of BullCowClass
acts as the view in MVC pattern, is responsible for all user interaction, for game logic see FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//entry point for the application
int main() {
	bool AskPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
	} while (AskPlayAgain);
	return 0; //exit the application
}

void PrintIntro() {
	//introduce the game
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetValidWordLength() << " letter isogram I'm thinking about?\n";
	return;
}

void PlayGame() {
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	do {
		FText Guess = GetGuess();
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
	}
	// TODO make check for valid guesses
	while (CurrentTry < MaxTries);
		
	// TODO summarise the game

	return;
}

//TODO change to GetValidGuess
FText GetGuess() {
	//get a guess from the user
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess:";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskPlayAgain() {
	std::cout << "Do you want to play again? (y/n) \n";
	FText Response = "";
	std::getline(std::cin,Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

