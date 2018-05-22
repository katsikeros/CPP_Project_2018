#pragma once
#include "Ship.h"
class Destroyer :
	public Ship
{
public:
	Destroyer();
	~Destroyer();

	int getSize();

protected:
	int size;
};
