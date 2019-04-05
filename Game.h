#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>

class Game {
	public:
		Game();
		~Game();
		void startgame();
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