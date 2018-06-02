#include "stdafx.h"
#include <iostream>
#include <vector>
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

Tile Board::getBoardTile(int x, int y)
{
	return this->my_board[x][y];
}

void Board::setBoardTile(int x, int y, typos t)
{
	this->my_board[x][y].setType(t);
}


void Board::drawboards(Tile my_board[7][7], Tile op_board[7][7])
{
	cout << "-  -  Y  O  U  -  -      -  O  P  P  O  N  E  N  T  -" << endl;
	cout << "  0  1  2  3  4  5  6        0  1  2  3  4  5  6" << endl;
	int i, j;
	for (i = 0; i <= 6; i++)
	{	
		cout << i << " ";
		for (j = 0; j <= 6; j++)
		{
			my_board[i][j].draw(false);
			cout << "  ";
		}
		cout << "    " << i << " ";;
		for (j = 0; j <= 6; j++)
		{
			op_board[i][j].draw(false);
			cout << "  ";
		}
		cout << endl;
	}
}

vector <coords> Board::getAdjacentTiles(coords tile)
{
	vector <coords> adjacent;
	if (tile.x - 1 >= 0) adjacent.push_back({ tile.x - 1, tile.y });
	if (tile.x + 1 < 7) adjacent.push_back({ tile.x + 1, tile.y });
	if (tile.y + 1 < 7) adjacent.push_back({ tile.x, tile.y + 1 });
	if (tile.y - 1 >= 0) adjacent.push_back({ tile.x, tile.y - 1 });
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

	srand(time(NULL));
	int rand_x , rand_y , rand_orient, placedCount = 0;
	Tile start;

	while (placedCount < 5) {
		rand_x = rand() % 7;
		rand_y = rand() % 7;
		rand_orient = rand() % 2;
		start.setCoords(rand_x, rand_y);

		//Trying to place Ship one by one from biggest to smallest (more chances it won't fail). If one is placed go to the next one
		switch (placedCount)
		{
		case 0:
			if (car1.placeShip(start, rand_orient, this->my_board, false) == true) placedCount++;
			break;
		case 1:
			if (bat1.placeShip(start, rand_orient, this->my_board, false) == true) placedCount++;
			break;
		case 2:
			if (crus1.placeShip(start, rand_orient, this->my_board, false) == true) placedCount++;
			break;
		case 3:
			if (sub1.placeShip(start, rand_orient, this->my_board, false) == true) placedCount++;
			break;
		case 4:
			if (destr1.placeShip(start, rand_orient, this->my_board, false) == true) placedCount++;
			break;
		default:
			break;
		}

	}
}
