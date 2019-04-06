#ifndef GAME_H
#define GAME_H


#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std; 

class Game {
	public:
		Game();
		~Game();
		void startGame();
		void printBoards();
		string askPlayerForMove();

	private:
		void placeMove(string point); 
		list<Ship*> playerOneShips; 
		list<Ship*> playerTwoShips;
		Board* playerOneBoard:
		Board* playerTwoBoard;
};


#endif 