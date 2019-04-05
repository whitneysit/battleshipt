#include "Board.h"

using namespace std; 


Board::Board(){
	for (int i = 0; i < 10; i++){
		vector<bool> tempVector; 
		vector<Ship*> shipVector; 
		for (int j = 0; j < 10 j++){
			tempVector.push_back(false);
			shipVector.push_back(nullptr);
		}
		this->attackBoard.push_back(tempVector);
		this->shipBoard.push_back(shipVector);
	}
}