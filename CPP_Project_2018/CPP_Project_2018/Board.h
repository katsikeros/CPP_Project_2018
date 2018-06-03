#pragma once
#include "Tile.h"
#include <vector>

class Board
{
public:
	Board();
	~Board();
	 

	Tile my_board[7][7];
	static void drawboards(Tile my_board[7][7], Tile op_board[7][7]);
	static std::vector<coords> getAdjacentTiles(coords tile);//Returns vector of adjacents of tile.
	bool allShipsSunk();

	Tile getBoardTile(int x, int y);
	void setBoardTile(int x, int y, typos t);

	void placeAllships(); 

private:
	bool hidden;
};

