#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Ship.h"
#include "Position.h"
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
		void printBoards(int player);
		string askPlayerForMove();
		string getInput(string output);

		bool isValidPosition(string pos);

	private:
		 // returns 1 if hit, 0 for miss, and -1 if already attacked
		list<Ship*> playerOneShips; 
		list<Ship*> playerTwoShips;
		Board* playerOneBoard;
		Board* playerTwoBoard;
		void placeShipsPrompt();
		void startAttacks();

		
};


#endif 