#include "stdafx.h"
#include "Carrier.h"


Carrier::Carrier()
{
	this->size = 5;
}


Carrier::~Carrier()
{
}

int Carrier::getSize()
{
	return this->size;
}