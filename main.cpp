#include <iostream>
#include "Board.h"
#include <string>

using namespace std; 

int main(int argc, char* argv[]){
	cout << "hello world" << endl;
	Board* board = new Board(); 
	board->printBoard(); 
}
