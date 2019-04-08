#include "Board.h"
#include "Ship.h"
#include "Position.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std; 

Board::Board(){
	for (int i = 0; i < 10; i++){
		vector<bool> tempVector; 
		vector<Ship*> shipVector; 
		for (int j = 0; j < 10; j++){
			tempVector.push_back(false);
			shipVector.push_back(nullptr);
		}
		this->attackBoard.push_back(tempVector);
		this->shipBoard.push_back(shipVector);
	}
	Ship* carrier = new Ship("Carrier", 5); 
	Ship* battleship = new Ship("Battleship", 4);
	Ship* cruiser = new Ship("Cruiser", 3); 
	Ship* submarine = new Ship("Submarine", 3);
	Ship* destroyer = new Ship("Destroyer", 2);
 	this->allShips.push_back(carrier);
 	this->allShips.push_back(battleship);
 	this->allShips.push_back(cruiser);
 	this->allShips.push_back(submarine);
 	this->allShips.push_back(destroyer);
}

Board::~Board(){
	for (int i = 0; i < 5; i++){
		delete allShips[i];
	}
}

void Board::printBoard(){
	cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
	for (int i = 0; i < 10; i++){
		cout << string(1,'a' + i) << " ";
		for (int j = 0; j < 10; j++){
			if (attackBoard[i][j]){
				if (shipBoard[i][j] != nullptr){
					cout << "* ";
				}
				else {
					cout << "x ";
				}	
			}
			else {
				if (shipBoard[i][j] != nullptr){
					cout <<  "+ ";
				}
				else {
					cout << "o ";
				}	
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}


bool Board::isTaken(Position& pos){
	return attackBoard[pos.x][pos.y]; 
}
bool Board::isHit(Position& pos){
	return (isTaken(pos) && shipBoard[pos.x][pos.y]); 
}
bool Board::placeShip(Ship* ship, Position pos, bool isHorizontal){
	int shipSize = ship->getSize();
	if (isHorizontal){
		for (int i = 0; i < shipSize; i++){
			if(shipBoard[pos.x][pos.y + i] != nullptr){
				return false; 
			}
		}
	}
	else {
		for (int i = 0; i < shipSize; i++){
			if(shipBoard[pos.x + i][pos.y] != nullptr){
				return false; 
			}
		}
	}
	if (isHorizontal){
		if ((pos.y + shipSize) > 10){
			return false; 
		}
		for (int i = 0; i < shipSize; i++){
			shipBoard[pos.x][pos.y + i] = ship;
		}
		return true; 
	}
	else {
		if ((pos.x + shipSize) > 10){
			return false; 
		}
		for (int i = 0; i < shipSize; i++){
			shipBoard[pos.x + i][pos.y] = ship;
		}
		return true; 
	}
	return false; 
} 

int Board::attack(Position& pos){
	if (isTaken(pos)){
		return -1; 
	}
	else if (shipBoard[pos.x][pos.y] != nullptr){
		attackBoard[pos.x][pos.y] = true; 
		shipBoard[pos.x][pos.y]->numOfHits++;
		return 1;
	}
	else {
		attackBoard[pos.x][pos.y] = true; 
		return 0; 
	} 
}