#pragma once
#include "Tile.h"
#include "Board.h"

class Ship
{
public:
	Ship();
	~Ship();

	//Tile start;
	//bool orientation; //0 horizontal, 1 vertical

	int size;

	bool placeShip(Tile start, bool orientation, Tile board[7][7], bool verbose);
};
