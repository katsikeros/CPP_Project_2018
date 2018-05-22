#pragma once

enum typos { Sea, Ship, Hit, Miss };

struct coords
{
	int x;
	int y;
};

class Tile
{
public:
	Tile();
	~Tile();

	typos getType();

	void setType(typos new_t);

	coords getCoords();

	void setCoords(int new_x, int new_y);

	void draw(bool hidden);

private:
	coords c;
	typos t;
};


