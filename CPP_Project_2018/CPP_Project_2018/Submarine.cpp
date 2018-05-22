#include "stdafx.h"
#include "Submarine.h"


Submarine::Submarine()
{
	this->size = 3;
}


Submarine::~Submarine()
{
}

int Submarine::getSize()
{
	return this->size;
}