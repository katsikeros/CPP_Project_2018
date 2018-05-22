#include "stdafx.h"
#include "Battleship.h"


Battleship::Battleship()
{
	this->size = 4;
}


Battleship::~Battleship()
{
}

int Battleship::getSize()
{
	return this->size;
}