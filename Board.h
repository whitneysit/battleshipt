#ifndef BOARD_D
#define BOARD_D

#include "Game.h"
#include "Ship.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Board {
	public:
		Board();
		~Board();
		bool isTaken(string pos); //return true is pos is already been attacked
		bool isHit(string pos); //return true if pos is already been hit
		void placeShip(Ship* ship); 

	private:
		vector< vector<Ship*> > shipBoard; 
		vector< vector<bool> > attackBoard; 
};


#endif 