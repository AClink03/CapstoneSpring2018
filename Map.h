#pragma once

class Location;
class Render;
class Tile;

class Tile
{

private:

public:
	/*
		Tile holds properties of the particular square in any given map. This includes;
		- Location of the Tile
		- List of pointers to the actors on the Tile
		- if the Tile is a map boundary or not
		- if the Tile is a Guidestone waypoint or not
		- ASCII character of the background (should there be one)
		- TCODColor code to render 
	*/
	Location loc; // location of tile, may not need?
	// std::vector<Actor *> contains; 
	bool bounds; // is this tile a boundary or not?
	Render rend; // render info for the tile
	bool guidestone; // is the tile a guidestone waypoint or not


	Tile(int x, int y, bool edge);
	Tile();
	~Tile();

	void RenderTile() const;
	void tRenderVals(Render * rend);
	void setTile(int x, int y, bool edge);

};

class Map
{
private:

public:
	Tile ** tiles;
	std::vector<Tile> landmarks;
	int width, height;
	
	Map(int width, int height);
	Map();
	~Map();
	void mRender();
	void makeLandmarks(int num);
};