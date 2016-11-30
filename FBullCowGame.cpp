#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	Reset();
}

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

void FBullCowGame::Reset() {
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
	return;
}


int FBullCowGame::GetAWordLength() {
	return 0;
}

std::string FBullCowGame::GetANewWord() {
	return std::string();
}


bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}
