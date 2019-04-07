#include "Ship.h"
#include <string>

using namespace std; 

Ship::Ship(string name, int size){
	this->name = name;
	this->size = size; 
	this->numOfHits = 0;
}

Ship::~Ship(){
	
}