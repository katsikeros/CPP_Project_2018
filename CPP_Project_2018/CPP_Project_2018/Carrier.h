#pragma once
#include "Ship.h"
class Carrier :
	public Ship
{
public:
	Carrier();
	~Carrier();

	int getSize();

protected:
	int size;
};

