#pragma once
#include "Tile.h"

class Board
{
public:
	Board();
	~Board();

	void drowboards();
	coords* getAdjacentTiles(coords tile);//Returns array of the 4 adjacent of tile. May return coords out of board
	bool allShipsSunk();

private:
	bool hidden;
	Tile my_board[7][7];
	Tile op_board[7][7];
};

