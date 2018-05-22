#pragma once
#include "Ship.h"
class Battleship :
	public Ship
{
public:
	Battleship();
	~Battleship();

	int getSize();

protected:
	int size;
};

