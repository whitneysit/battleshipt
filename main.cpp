#include <iostream>
#include <string>
#include "Board.h"
#include "Game.h"

using namespace std; 

int main(int argc, char* argv[]){
	cout << "hello world" << endl;
	Board* board = new Board(); 
	board->printBoard(); 
	Game* game = new Game(); 
	game->startGame();
}
