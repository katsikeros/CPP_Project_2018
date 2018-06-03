#include "stdafx.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Submarine.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battleship.h"

Player::Player()
{
}


Player::~Player()
{
}


void Player::placeAllShips()
{
	this->board.placeAllships();
}

bool Player::placeShip(string ship, Tile start, bool orient)
{
	Submarine sub1;
	Battleship bat1;
	Destroyer destr1;
	Cruiser crus1;
	Carrier car1;


	if (ship == "Carrier") return car1.placeShip(start, orient, this->board.my_board, true);
	else if (ship == "Battleship") return bat1.placeShip(start, orient, this->board.my_board, true);
	else if (ship == "Cruiser") return crus1.placeShip(start, orient, this->board.my_board, true);
	else if (ship == "Submarine") return sub1.placeShip(start, orient, this->board.my_board, true);
	else if (ship == "Destroyer") return destr1.placeShip(start, orient, this->board.my_board, true);
}

void Player::fire(Tile boardToFire[7][7], coords c)
{

	this->throws++;
	if (boardToFire[c.x][c.y].getType() == Ship) {
		this->hits++;
		boardToFire[c.x][c.y].setType(Hit);
	}
	else if (boardToFire[c.x][c.y].getType() == Sea) {
		this->misses++;
		boardToFire[c.x][c.y].setType(Miss);
	}
	else if (boardToFire[c.x][c.y].getType() == Hit) this->repeats++;
	else if (boardToFire[c.x][c.y].getType() == Miss) this->repeats++;
}

void Player::getStats()
{
	cout << endl << "*******************************" << endl;
	cout << "Name : " << this->name << endl;
	cout << "Throws : " << this->throws << endl;
	cout << "Misses : " << this->misses << endl;
	cout << "Hits : " << this->hits << endl;
	cout << "Repeats : " << this->repeats << endl;
}
