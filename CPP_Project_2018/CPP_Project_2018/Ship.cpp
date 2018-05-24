#include "stdafx.h"
#include <iostream>
#include "Ship.h"
#include "Board.h"

using namespace std;

namespace Ship_space{
	enum typos { Sea, Ship, Hit, Miss };
}

Ship::Ship()
{
}


Ship::~Ship()
{
}

bool Ship::placeShip(Tile start, bool orientation, Tile board[7][7], bool verbose)
{
	coords my_c = start.getCoords();
	
	
	cout<<endl << " ********** placeShip ********** " << endl;
	
	cout << endl << " ( " << my_c.x << " , " << my_c.y <<" )    size = " << this->size;
	
	if ( orientation == 1 ) {
		cout << " oriented right " << endl << endl;
	}
	else {
		cout << "  oriented down " << endl << endl;
	}
	

	if (my_c.x < 0 || my_c.x > 6 || my_c.y < 0 || my_c.y > 6)
	{
		cout << "Starting Tile is out of the board" << endl;
		return false;
	}

	int temp_x = my_c.x, temp_y = my_c.y;

	if (orientation == 1 && my_c.x <=4 ) {
		
		for (int i = 0; i < this->size; i++) {

			if ( board[temp_x][temp_y].getType() == Sea) {
				temp_x = temp_x + 1;
				
			}
			else {
				return 0;
			}
		}
		temp_x = my_c.x;
		
		for (int i = 0; i < this->size; i++) {
			
			if ( board[temp_x][temp_y].getType() == Sea) {
				cout << " tempx = " << temp_x << "     temp_y = " << temp_y << endl;
				board[temp_x][temp_y].setType((typos)Ship_space::Ship);
				temp_x = temp_x + 1;
			}
		}

	}
	else if (orientation == 0 && my_c.y <= 4) {
		for (int i = 0; i < this->size; i++) {

			if (board[temp_x][temp_y].getType() == Sea) {
				temp_y = temp_y + 1;
			}
			else {
				return 0;
			}
		}
		temp_y = my_c.y;

		for (int i = 0; i < this->size; i++) {

			if (board[temp_x][temp_y].getType() == Sea) {
				cout << " tempx = " << temp_x << "     temp_y = " << temp_y << endl;
				board[temp_x][temp_y].setType((typos)Ship_space::Ship);
				temp_y = temp_y + 1;
			}
		}
	}
	
	
	cout << " ******************************* " <<endl<< endl;
	return 1;

}