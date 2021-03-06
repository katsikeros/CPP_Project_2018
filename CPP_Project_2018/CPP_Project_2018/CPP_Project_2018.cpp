// CPP_Project_2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include "Tile.h"
#include "Ship.h"
#include "Board.h"
#include "Player.h"
using namespace std;
using std::cout;

coords getInput()
{	
	int x, y;
	cout << "Please insert coordinates : ";
	cin >> x >> y;

		/*string str;
		cout << "Please insert coordinates : ";
		cin.clear();
		std::getline(std::cin, str);
		string end_string;
		cout << "asdasdasdasdasda " << str << endl;

		int x, y, i = 0, count = 0;
		while (i < str.size() || count < 2) {
			if (isdigit(str[i])) {
				cout << " c : " << str[i] << endl;
				if (count == 0)
				{
					x = (int)str[i];
					count++;
				}
				else if (count == 1)
				{
					y = (int)str[i];
					count++;
				}
				end_string.push_back(str[i]);
				end_string.push_back(' ');
			}
			i++;
		}
*/



	/*string s = " ", temp, str;
	stringstream ss;
	int x, y, counter;
	cout << "Please insert coordinates : ";
	cin.ignore();
	getline(cin, s);
	str.append("asdf ");
	str.append(s);
	cout << " strimg " << str << endl;
	ss << str;
	counter = 0;
	while (counter < 2)
	{
		ss >> temp;
		cout << " aaaaaaaaaaaaaaaa " << counter << temp << endl;
		if ((counter == 0) && (stringstream(temp) >> x)) counter++;
		else if ((counter == 1) && (stringstream(temp) >> y)) counter++;
		temp = "";
	}
	

	while (x < 0 || x > 6 || y < 0 || y > 6)
	{
		cout << "Inserted coordinates out of board. Please insert correct coordinates : ";
		cin.ignore();
		getline(cin, str);

		ss << str;

		counter = 0;
		while (counter < 2)
		{
			cout << " aaaaaaaaaaaaaaaa sto mesa" << endl;
			ss >> temp;
			if ((counter == 0) && (stringstream(temp) >> x)) counter++;
			else if ((counter == 1) && (stringstream(temp) >> y)) counter++;
			temp = "";
		}
	}
	cin.clear();*/
	return {x, y};
}


coords getRandInput() {//returns random coords from 0-6
	int x, y;
	x = rand() % 7;
	y = rand() % 7;
	return {x, y};


}

bool getOrientation()//1 for vertical, 0 for horizontal
{
	char c;
	cout << "Insert orientation you want (V for vertical, H for horizontal) : ";
	cin >> c;

	while (c != 'H' && c != 'V' && c != 'h' && c != 'v')
	{
		cout << "Inserted wrong input. Please insert orientation you want (V for vertical, H for horizontal) : ";
		cin >> c;
	}
	
	if (c == 'V' || c == 'v') return 1;
	else return 0;
}

bool randomPlace()
{
	char c;
	cout << "Do you want to insert ships randomly? (Y for yes, N for no) : ";
	cin >> c;

	while (c != 'N' && c != 'Y' && c != 'n' && c != 'y')
	{
		cout << "Inserted wrong input. Do you want to insert ships randomly? (Y for yes, N for no) : ";
		cin >> c;
	}

	if (c == 'Y' || c=='y') return true;
	else return false;
}

int main()
{


	Player player;
	Player computer;
	
	player.name = "You";
	computer.name = "Opponent";
	srand(time(NULL));
	bool c = randomPlace();
	if (c == true)
	{
		player.placeAllShips();
	}
	else
	{
		cout << "************" << endl;
		cout << "Ships are : " << endl;
		cout << "Carrier (5 slots)" << endl;
		cout << "Battleship (4 slots)" << endl;
		cout << "Cruiser (3 slots)" << endl;
		cout << "Submarine (3 slots)" << endl;
		cout << "Destroyer (2 slots)" << endl;
		cout << "************" << endl << endl;
		Board::drawboards(player.board.my_board, computer.board.my_board);
		cout << "Inserting Carrier (5 slots).." << endl;
		bool orient = getOrientation();
		coords my_coords = getInput();
		Tile start = player.board.getBoardTile(my_coords.x, my_coords.y);
		while (player.placeShip("Carrier", start, orient) == false) {
			orient = getOrientation();
			my_coords = getInput();
			start = player.board.getBoardTile(my_coords.x, my_coords.y);
		}
		Board::drawboards(player.board.my_board, computer.board.my_board);
		cout << "Inserting Battleship (4 slots).." << endl;
		orient = getOrientation();
		my_coords = getInput();
		start = player.board.getBoardTile(my_coords.x, my_coords.y);
		while (player.placeShip("Battleship", start, orient) == false) {
			orient = getOrientation();
			my_coords = getInput();
			start = player.board.getBoardTile(my_coords.x, my_coords.y);
		}
		Board::drawboards(player.board.my_board, computer.board.my_board);
		cout << "Inserting Cruiser (3 slots).." << endl;
		orient = getOrientation();
		my_coords = getInput();
		start = player.board.getBoardTile(my_coords.x, my_coords.y);
		while (player.placeShip("Cruiser", start, orient) == false) {
			orient = getOrientation();
			my_coords = getInput();
			start = player.board.getBoardTile(my_coords.x, my_coords.y);
		}
		Board::drawboards(player.board.my_board, computer.board.my_board);
		cout << "Inserting Submarine (3 slots).." << endl;
		orient = getOrientation();
		my_coords = getInput();
		start = player.board.getBoardTile(my_coords.x, my_coords.y);
		while (player.placeShip("Submarine", start, orient) == false) {
			orient = getOrientation();
			my_coords = getInput();
			start = player.board.getBoardTile(my_coords.x, my_coords.y);
		}
		Board::drawboards(player.board.my_board, computer.board.my_board);
		cout << "Inserting Destroyer (2 slots).." << endl;
		orient = getOrientation();
		my_coords = getInput();
		start = player.board.getBoardTile(my_coords.x, my_coords.y);
		while (player.placeShip("Destroyer", start, orient) == false) {
			orient = getOrientation();
			my_coords = getInput();
			start = player.board.getBoardTile(my_coords.x, my_coords.y);
		}


	}

	computer.placeAllShips();
	Board::drawboards(player.board.my_board, computer.board.my_board);

	cout << "******* Starting Game ********" << endl;

	while ((player.board.allShipsSunk() == false) && (computer.board.allShipsSunk() == false))
	{
		cout << "It is your time to fire!!" << endl;
		player.fire(computer.board.my_board, getInput());


		cout << "Oh no!! We are under attack!" << endl;
		computer.fire(player.board.my_board, getRandInput());

		Board::drawboards(player.board.my_board, computer.board.my_board);
	}

	cout << endl << "We have a winner! Congratulations player : ";

	if (player.board.allShipsSunk() == true) cout << computer.name << endl << endl;
	else if (computer.board.allShipsSunk() == true)  cout << player.name << endl << endl;

	cout << "Stats for player : " << player.name;
	player.getStats();
	cout << endl << endl << "Stats for player : " << computer.name;
	computer.getStats();
	cout << endl << endl << "********  Game ended  ********" << endl;
	return 0;
}