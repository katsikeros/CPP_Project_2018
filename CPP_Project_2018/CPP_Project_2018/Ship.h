#pragma once
#include "Tile.h"
#include "Board.h"

class Ship
{
public:
	Ship();
	~Ship();

	//Tile start;

	int size;

	bool placeShip(Tile start, bool orientation, Tile board[7][7], bool verbose);//1 vertical, 0 horizontal, verbose true -> print exceptions, else not
};
