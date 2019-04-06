#ifndef SHIP_H
#define SHIP_H

#include "Board.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <string>


class Ship {
	public:
		Ship(int size);
		~Ship();

	private:
		int size;
		int	numOfHits;
};


#endif 