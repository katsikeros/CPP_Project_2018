#pragma once
#include <string>
#include "Tile.h"
#include "Board.h"
#include "Ship.h"
using namespace std;

class Player
{
public:
	Player();
	~Player();

	Board board;

	void placeAllShips();
	bool placeShip(string ship, Tile start, bool orient);
	void fire(Tile boardToFire[7][7], coords c);
	void getStats();

private:
	string name;
	int throws, misses, hits, repeats;
};

