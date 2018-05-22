#pragma once
#include "Ship.h"
class Submarine :
	public Ship
{
public:
	Submarine();
	~Submarine();

	int getSize();

protected:
	int size;
};

