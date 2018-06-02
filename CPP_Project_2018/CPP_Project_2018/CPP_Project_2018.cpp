// CPP_Project_2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "Ship.h"
#include "Board.h"
using namespace std;


int main()
{
	

	Board player_Board;
	Board computer_Board;

	player_Board.placeAllships();
	computer_Board.placeAllships();
	
	Board::drawboards(player_Board.my_board, computer_Board.my_board);

	return 0;
}