#pragma once
#include "Tile.h"

class Ship
{
public:
	Ship();
	~Ship();

	//Tile start;
	//bool orientation; //0 horizontal, 1 vertical

	bool placeShip(Tile start, bool orientation, int board[7][7], bool verbose);
};
