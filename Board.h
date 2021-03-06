#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include "Position.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Board {
	public:
		Board();
		~Board();
		void printBoard(); 
		void printHiddenBoard();
		bool isTaken(Position& pos); //return true is pos is already been attacked
		bool isHit(Position& pos); //return true if pos is already been hit
		bool placeShip(Ship* ship, Position pos, bool isHorizontal); // return true if success else false
		int attack(Position& pos); // return -1 if already attacked, 0 if missed, 1 if hit
		Ship* getShip(int index){return allShips[index];}

	private:
		vector< vector<Ship*> > shipBoard; 
		vector< vector<bool> > attackBoard; 
		vector<Ship*> allShips;
		int numOfHits; //number of the holes that were hit (has ship and attacked)  
		int numOfTotalHits;
};


#endif 