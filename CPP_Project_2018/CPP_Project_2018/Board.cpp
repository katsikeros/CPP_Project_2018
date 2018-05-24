#include "stdafx.h"
#include <iostream>
#include <time.h>       /* time */
#include "Ship.h"
#include "Board.h"
#include "Submarine.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battleship.h"

using namespace std;

Board::Board()
{
	int i, j;
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 6; j++)
		{
			this->my_board[i][j].setCoords(i,j);
			this->my_board[i][j].setType(Sea);
			this->op_board[i][j].setCoords(i, j);
			this->op_board[i][j].setType(Sea);
		}

	}
}


Board::~Board()
{
}

void Board::drowboards()
{
	cout << "-  -  Y  O  U  -  -      -  O  P  P  O  N  E  N  T  -" << endl;
	cout << "  0  1  2  3  4  5  6        0  1  2  3  4  5  6" << endl;
	int i, j;
	for (i = 0; i <= 6; i++)
	{	
		cout << i << " ";
		for (j = 0; j <= 6; j++)
		{
			this->my_board[i][j].draw(false);
			cout << "  ";
		}
		cout << "    " << i << " ";;
		for (j = 0; j <= 6; j++)
		{
			this->op_board[i][j].draw(true);
			cout << "  ";
		}
		cout << endl;
	}
}

coords* Board::getAdjacentTiles(coords tile)
{
	coords adjacent[4] = { NULL };
	adjacent[0] = { tile.x - 1, tile.y };
	adjacent[1] = { tile.x + 1, tile.y };
	adjacent[2] = { tile.x, tile.y + 1 };
	adjacent[3] = { tile.x, tile.y - 1 };
	return adjacent;
}

bool Board::allShipsSunk()//Counts ships in both boards, if one of them doesn't have any left, returns true
{
	int i, j,count_my = 0 ,count_op = 0;  
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 6; j++)
		{
			if (this->my_board[i][j].getType() == Ship) count_my++;
			if (this->op_board[i][j].getType() == Ship) count_op++;
		}

	}

	if (count_my == 0 || count_op == 0) return true;
	else return false;
}

void Board::placeAllships() {  
	
	Submarine sub1;
	Battleship bat1;
	Destroyer destr1;
	Cruiser crus1;
	Carrier car1;

	srand(2);
	int rand_x , rand_y , rand_orient;
	Tile start;

	for (int i = 0; i < SHIP_NUM; i++) {
		rand_x = rand() % 7;
		rand_y = rand() % 7;
		rand_orient = rand() % 2;
		start.setCoords( rand_x , rand_y );
		
		if ( i == 0 ) {
		 sub1.placeShip(start, rand_orient, this->my_board, 1);
		} 
		else if ( i ==1 ) { bat1.placeShip(start, rand_orient, this->my_board, 1); }
		else if (i == 2) { destr1.placeShip(start, rand_orient, this->my_board, 1);  }
		else if (i == 3) { crus1.placeShip(start, rand_orient, this->my_board, 1);  }
		else if (i == 4) { car1.placeShip(start, rand_orient, this->my_board, 1);  }


		this->drowboards();
		
	}
}