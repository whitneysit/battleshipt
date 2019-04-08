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
					isSuccess = this->playerOneBoard->placeShip(this->playerOneBoard->getShip(i), Position(pos), direction=="h");
				}
				else {
					isSuccess = this->playerOneBoard->placeShip(this->playerOneBoard->getShip(i), Position(pos), direction=="h");
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
		cout << "iteration: " << i << endl;
		string shipName = this->playerTwoBoard->getShip(i)->getName();
		int shipSize = this->playerTwoBoard->getShip(i)->getSize();
		string prompt = "Player 2, where would you like to place your " + 
			shipName + " of " + to_string(shipSize) + " holes? (example: b4)";
		string pos = getInput(prompt);
		bool isSuccess = false;
		
		while (isSuccess == false){
			if (isValidPosition(pos)){
				string direction = getInput("Which direction do you want to place it? (h/v)");
				if (pos.size() == 3){
					isSuccess = this->playerTwoBoard->placeShip(this->playerTwoBoard->getShip(i), Position(pos), direction=="h");
				}
				else {
					isSuccess = this->playerTwoBoard->placeShip(this->playerTwoBoard->getShip(i), Position(pos), direction=="h");
				}
				if (isSuccess == false){
					pos = getInput("You cannot place your ship there. Please try again with another position.");
				}
			}
			else {
				while (!isValidPosition(pos)){
					pos = getInput("invalid position, please enter a valid position");
				}
			}
			cout << "Player 2:" << endl;
			this->playerTwoBoard->printBoard();
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
	cout << "in start Attacks" << endl;
	int counter = 0; 
	while (true){
		if (counter % 2){
			string pos = "";
			while(isValidPosition(pos)){
				pos = getInput("Player 1, it's your turn to attack. Please enter a position. (Example: b4)");
				if (!isValidPosition(pos)){
					cout << "invalid position" << endl;
				}
			}
			Position position(pos);
			switch(this->playerOneBoard->attack(position)){
				case 0:
					cout << "Missed!" << endl;
					counter++;
					break;
				case 1:
					cout << "Hit!" << endl;
					counter++;
					break;
				case -1:
					cout << "You already attacked this position. Your turn will repreat." << endl;
					break;
			}
		}
		else {
			string pos = "";
			while(isValidPosition(pos)){
				pos = getInput("Player 2, it's your turn to attack. Please enter a position. (Example: b4)");
				if (!isValidPosition(pos)){
					cout << "invalid position" << endl;
				}
			}
			Position position(pos);
			switch(this->playerTwoBoard->attack(position)){
				case 0:
					cout << "Missed!" << endl;
					counter++;
					break;
				case 1:
					cout << "Hit!" << endl;
					counter++;
					break;
				case -1:
					cout << "You already attacked this position. Your turn will repreat." << endl;
					break;
			}

		}
		printBoards();
	}
	return;
}