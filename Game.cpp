#include "Game.h"

#include <string>
#include <iostream>

using namespace std; 

Game::Game(){
	playerOneBoard = new Board(); 
	playerTwoBoard = new Board(); 
}

Game::~Game(){
	delete playerOneBoard; 
	delete playerTwoBoard;
}

void Game::startGame(){
	while (!(getInput("Are you ready Player 1? (y/n)")=="y")){}
	while (!(getInput("Are you ready Player 2? (y/n)")=="y")){}
	placeShipsPrompt();
	return; 
}

void Game::printBoards(){
	playerOneBoard->printBoard(); 
	playerTwoBoard->printBoard(); 
	return; 
}

string Game::getInput(string output){
	cout << output << endl; 
	string answer;
	cin >> answer; 
	return answer;
}

void Game::placeShipsPrompt(){
	cout << "It's time to place your ships, Player 1!" << endl;
	for (int i = 0; i < 5; i++){
		string shipName = this->playerOneBoard->getShip(i)->getName();
		int shipSize = this->playerOneBoard->getShip(i)->getSize();
		string prompt = "Player 1, where would you like to place your " + shipName + " of " + to_string(shipSize) + "? (example: b4)";
		string pos = getInput(prompt);

	}
}

bool Game::isValidPosition(string position){
	if (position.size() == 2 || position.size() == 3)
	{
		if (!((position[0] >= 'a' && position[1] <= 'z') || (position[0] >= 'A' && position[1] <= 'Z'))){
			return false; 
		} 
		if (position[1] >= '0' && position[1] <= '9'){
			if (position.size() == 3){
				if (position[1] == '1'){
					if (position[2] == '0'){
						return true; 
					}
				}
				else {
					return false; 
				}
			}
			else {
				return true; 
			}
		}

	}
	else
	{
		return false; 
	}
}