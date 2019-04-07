#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Ship {
	public:
		Ship(string name, int size);
		~Ship();
		bool isCovered(){ return size == numOfHits; }
		string getName(){ return name;} 
		int getSize(){return size;}
		int	numOfHits;

	private:
		string name; 
		int size;
};


#endif 