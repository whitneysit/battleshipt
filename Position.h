#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <vector>
#include <string>


class Position {
	public:
		Position(char x, int y){
			if (x >= 'A' && x <= 'Z'){
				this->x = x - 'A'; 
			}
			else {
				this->x = x - 'a';
			}

			this->y = y; 
		}
		Position(string pos){
			char x = pos[0];
			if (x >= 'A' && x <= 'Z'){
				this->x = x - 'A'; 
			}
			else {
				this->x = x - 'a';
			}
			if (pos.size() == 3){
				string number = string(1, pos[1]) + string(1, pos[2]);
				this->y = stoi(number) - 1;
			}
			else {
				string number = string(1, pos[1]);
				this->y = stoi(number) - 1;
			}
		}
		~Position(){}
		int x; 
		int y; 
};


#endif 