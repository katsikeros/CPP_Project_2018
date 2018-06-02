#include "stdafx.h"
#include <iostream>
#include <vector>
#include <exception>
#include "Ship.h"
#include "Board.h"

using namespace std;

namespace Ship_space{//ginetai giati ean vazame ws orisma se sinartisi to Ship to eperne ws tin sinartisi Ship
	enum typos { Sea, Ship, Hit, Miss };
}

class OversizeException : public exception
{
	virtual const char* what() const throw()
	{
		return "Ship is out of the Board";
	}
};

class OverlapTilesException : public exception
{
	virtual const char* what() const throw()
	{
		return "Ship was placed on top of another one";
	}
};

class AdjacentTilesException : public exception
{
	virtual const char* what() const throw()
	{
		return "Ship osculates on another one";
	}
};

Ship::Ship()
{
}


Ship::~Ship()
{
}

bool Ship::placeShip(Tile start, bool orientation, Tile board[7][7], bool verbose)
{
	try {
		coords my_c = start.getCoords();


		if (my_c.x < 0 || my_c.x > 6 || my_c.y < 0 || my_c.y > 6)//CHeck if starting tile is in the board
		{
			cout << "Starting Tile is out of the board" << endl;
			return false;
		}

		for (int i = 0; i < this->size; i++)//exceptions 
		{
			if (orientation == 1)//vertical
			{
				if (my_c.x + i > 6) throw OversizeException();//Ship out of board
				if (board[my_c.x + i][my_c.y].getType() == (typos)Ship_space::Ship) throw OverlapTilesException();//Ship ontop of another one

				vector <coords> temp = Board::getAdjacentTiles({ my_c.x + i , my_c.y});//pairnoume kathe fora ta gitonika tou epomenou Tile tou ship
				for (int j = 0; j < temp.size(); j++)
				{
					if (board[temp[j].x][temp[j].y].getType() == (typos)Ship_space::Ship)
					{
						throw AdjacentTilesException();//Ship near another one
					}
				}
			}
			else//horizontal
			{
				if (my_c.y + i > 6) throw OversizeException();
				if (board[my_c.x][my_c.y + i].getType() == (typos)Ship_space::Ship) throw OverlapTilesException();

				vector <coords> temp = Board::getAdjacentTiles({ my_c.x , my_c.y + i});
				for (int j = 0; j < temp.size(); j++)
				{
					if (board[temp[j].x][temp[j].y].getType() == (typos)Ship_space::Ship)
					{
						throw AdjacentTilesException();
					}
				}
			}

		}
		
		if (orientation == 1) for (int i = 0; i < this->size; i++) board[my_c.x + i][my_c.y].setType((typos)Ship_space::Ship); // vertical
		else if (orientation == 0) for (int i = 0; i < this->size; i++) board[my_c.x][my_c.y + i].setType((typos)Ship_space::Ship); // horizontal

	}
	catch (exception& e)
	{
		if (verbose == true) cout << e.what() << endl;
		return false;
	}


	return true;

}