#include <iostream>
#include <string>
#include "FBullCowGame.h"



void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskPlayAgain();

FBullCowGame BCGame; //instantiate a new game

//entry point for the application
int main() {
	do {
		PrintIntro();
		PlayGame();
	} while (AskPlayAgain());
	return 0; //exit the application
}

void PrintIntro() {
	//introduce the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking about?\n";
	return;
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	constexpr int TURNS = 5;
	for (int count = 1; count <= TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl << std::endl;
	};
	return;
}

std::string GetGuess() {
	//get a guess from the user
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess:";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskPlayAgain() {
	std::cout << "Do you want to play again? (y/n) \n";
	std::string Response = "";
	std::getline(std::cin,Response);
	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
	
}

