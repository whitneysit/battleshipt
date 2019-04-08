#include <iostream>
#include <string>
#include "Board.h"
#include "Game.h"

using namespace std; 

int main(int argc, char* argv[]){
	Game* game = new Game(); 
	game->startGame();
}
