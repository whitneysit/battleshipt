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
		~Position(){}
		int x; 
		int y; 
};


#endif 