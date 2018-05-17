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

//enum typos { Sea, Ship, Hit, Miss };
//struct coords
//{
//	int x;
//	int y;
//};

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
	coords c;
	c.x = 5;
	c.y = 2;
	return c;
}

void Tile::setCoords(int new_x, int new_y)
{
	coords c;
	c.x = new_x;
	c.y = new_y;
}

void Tile::draw(bool hidden)
{
	typos t = Sea;
	switch (t)
	{
	case Sea:
		cout << "~";
		break;
	case Ship:
		if (hidden == 1) cout << "~";
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

	return;
}
