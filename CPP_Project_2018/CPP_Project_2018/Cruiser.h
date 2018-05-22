#pragma once
#include "Ship.h"
class Cruiser :
	public Ship
{
public:
	Cruiser();
	~Cruiser();

	int getSize();

protected:
	int size;
};

