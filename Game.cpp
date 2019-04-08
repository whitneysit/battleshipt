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

	startAttacks();
	return; 
}

void Game::printBoards(){
	cout << "Player 1:" << endl;
	playerOneBoard->printBoard(); 
	cout << "Player 2:" << endl;
	playerTwoBoard->printBoard(); 
	return; 
}

string Game::getInput(string output){
	
	cout << output << endl; 
	string answer;
	cin.clear();
	cin >> answer; 
	cout << endl;
	return answer;
}

void Game::placeShipsPrompt(){
	cout << "It's time to place your ships, Player 1!" << endl;
	for (int i = 0; i < 5; i++){
		string shipName = this->playerOneBoard->getShip(i)->getName();
		int shipSize = this->playerOneBoard->getShip(i)->getSize();
		string prompt = "Player 1, where would you like to place your " + 
			shipName + " of " + to_string(shipSize) + " holes? (example: b4)";
		string pos = getInput(prompt);
		bool isSuccess = false;
		if (isValidPosition(pos)){
			while (isSuccess == false){
				string direction = getInput("Which direction do you want to place it? (h/v)");
				if (pos.size() == 3){
					string number = string(1, pos[1]) + string(1, pos[2]);
					isSuccess = this->playerOneBoard->placeShip(this->playerOneBoard->getShip(i), Position(pos[0], stoi(number) - 1), direction=="h");
				}
				else {
					string number = string(1, pos[1]);
					isSuccess = this->playerOneBoard->placeShip(this->playerOneBoard->getShip(i), Position(pos[0], stoi(number) - 1), direction=="h");
				}
				if (isSuccess == false){
					pos = getInput("You cannot place your ship there. Please try again with another position.");
				}
			}
			cout << "Player 1:" << endl;
			this->playerOneBoard->printBoard();
		}
		else {
			while (!isValidPosition(pos)){
				pos = getInput("invalid position, please enter a valid position");
			}
		}
	}

	cout << "It's time to place your ships, Player 2!" << endl;
	for (int i = 0; i < 5; i++){
		string shipName = this->playerTwoBoard->getShip(i)->getName();
		int shipSize = this->playerTwoBoard->getShip(i)->getSize();
		string prompt = "Player 2, where would you like to place your " + 
			shipName + " of " + to_string(shipSize) + " holes? (example: b4)";
		string pos = getInput(prompt);
		bool isSuccess = false;
		if (isValidPosition(pos)){
			while (isSuccess == false){
				string direction = getInput("Which direction do you want to place it? (h/v)");
				if (pos.size() == 3){
					string number = string(1, pos[1]) + string(1, pos[2]);
					isSuccess = this->playerTwoBoard->placeShip(this->playerTwoBoard->getShip(i), Position(pos[0], stoi(number) - 1), direction=="h");
				}
				else {
					string number = string(1, pos[1]);
					isSuccess = this->playerTwoBoard->placeShip(this->playerTwoBoard->getShip(i), Position(pos[0], stoi(number) - 1), direction=="h");
				}
				if (isSuccess == false){
					pos = getInput("You cannot place your ship there. Please try again with another position.");
				}
			}
			cout << "Player 1:" << endl;
			this->playerTwoBoard->printBoard();
		}
		else {
			while (!isValidPosition(pos)){
				pos = getInput("invalid position, please enter a valid position");
			}
		}
	}
}

bool Game::isValidPosition(string position){
	if (position.size() == 2 || position.size() == 3)
	{
		if (!((position[0] >= 'a' && position[1] <= 'z') || (position[0] >= 'A' && position[1] <= 'Z'))){
			return false; 
		} 
		if (position[1] >= '1' && position[1] <= '9'){
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
		else {
			return false; 
		}

	}
	else
	{
		return false; 
	}
	return false; 
}

void Game::startAttacks(){
 return;
}