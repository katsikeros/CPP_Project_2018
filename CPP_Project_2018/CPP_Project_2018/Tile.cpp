#include "stdafx.h"
#include "Tile.h"
#include <iostream>
#include <string>
using namespace std;

Tile::Tile()
{
}


Tile::~Tile()
{
}


void Tile::setType(typos new_t)
{
	this->t = new_t;
}


typos Tile::getType()
{
	return this->t;
}


coords Tile::getCoords()
{
	
	return this->c;
}

void Tile::setCoords(int new_x, int new_y)
{
	this->c.x = new_x;
	this->c.y = new_y;
}

void Tile::draw(bool hidden)
{
	switch (this->t)
	{
	case Sea:
		cout << "~";
		break;
	case Ship:
		if (hidden == true) cout << "~";
		else cout << "s";
		break;
	case Hit:
		cout << "X";
		break;
	case Miss:
		cout << "o";
		break;
	default:
		break;
	}
}
