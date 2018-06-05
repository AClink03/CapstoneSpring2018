#pragma once

class Location;
class AI;
class Render;
class Tile;
class Pilot;
class Airframe;

class Actor
{
private:

public:
	Location * loc;
	Render rend;
	Tile * tp;

	Actor(Location Loc, Render Rend, Tile * Tp);
	Actor();
	~Actor();

	void pRender() const;
	void Update(TCOD_key_t key);	// for the player
	void findTile(int h, int nh);
	void Move(int x, int y, int eh);
	int moveHelper(int md);
};