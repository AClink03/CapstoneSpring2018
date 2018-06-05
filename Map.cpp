#include "Main.h"

Tile::Tile(int x, int y, bool edge)
{
	
}

Tile::Tile()
{
	bounds = false;
	guidestone = false;
}

Tile::~Tile()
{
}

void Tile::RenderTile() const
{
	
}

void Tile::tRenderVals(Render * rend)
{
	
}

void Tile::setTile(int x, int y, bool edge)
{
	
}


Map::Map(int width, int height)
{
	this->width = width;
	this->height = height;

	// make the tiles
	tiles = new Tile*[width];
	for (int x = 0; x < width; x++)
	{
		tiles[x] = new Tile[height];
	}

	// fill the tiles with relevant info
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			Location tLoc = {x,y,false,false};
			Render tRend = { TCODColor::black, 0 };
			tiles[x][y].loc = tLoc;
			tiles[x][y].rend = tRend;
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
			{
				tiles[x][y].bounds = true;
			}						
		}
	}
}

Map::Map()
{
}

Map::~Map()
{

}

void Map::mRender()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{			
			TCODConsole::root->setCharBackground(x, y, tiles[x][y].rend.col);
		}
	}
}

void Map::makeLandmarks(int num)
{
	const int CENTERX = 39;
	const int CENTERY = 24;
	int randAlt;
	std::string wayName;
	Location wayLoc;


	for (int x = 0; x < num; x++)
	{
		srand(time_t(NULL));
		if (x == 0) // do this part once to set the first landmark
		{
			int randx = (rand() % 72) + 4; // gives 4 - 76
			int randy = (rand() % 42) + 4; // gives 4 - 46
			int randAlt = 10;			   // Randomize the altitude
			// gives 4-space boundary on all sides, to prevent planes from flying out of the AO
		}
		else if (x == num - 1)
		{

		}
		else if (x & 2 == 0)
		{

		}
		else
		{

		}
	}
}
