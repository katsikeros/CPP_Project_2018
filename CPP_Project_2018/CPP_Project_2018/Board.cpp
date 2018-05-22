#include "stdafx.h"
#include <iostream>
#include "Board.h"
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
	int i, j,count_my,count_op;
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