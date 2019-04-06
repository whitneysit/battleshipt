#include "Board.h"
#include "Ship.h"
#include <vector>
#include <iostream>

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
}

void Board::printBoard(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			cout << attackBoard[i][j];
			//cout << shipVector[i][j];
		}
		cout << endl;
	}
}


bool Board::isTaken(string pos){
	return false; 
}
bool Board::isHit(string pos){
	return false; 
}
void Board::placeShip(Ship* ship){
	return; 
} 