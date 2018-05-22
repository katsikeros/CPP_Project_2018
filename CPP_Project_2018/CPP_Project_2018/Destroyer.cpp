#include "stdafx.h"
#include "Destroyer.h"


Destroyer::Destroyer()
{
	this->size = 2;
}


Destroyer::~Destroyer()
{
}

int Destroyer::getSize()
{
	return this->size;
}