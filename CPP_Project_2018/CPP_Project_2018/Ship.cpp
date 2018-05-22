#include "stdafx.h"
#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship()
{
}


Ship::~Ship()
{
}

bool Ship::placeShip(Tile start, bool orientation, int board[7][7], bool verbose)
{
	coords my_c = start.getCoords();
	if (my_c.x < 0 || my_c.x > 6 || my_c.y < 0 || my_c.y > 6)
	{
		cout << "Starting Tile is out of the board" << endl;
		return false;
	}

}