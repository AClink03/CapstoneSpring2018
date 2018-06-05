#pragma once
#include <vector>
class Map;
class Tile;
class Actor;

class Engine
{
private:
	Map * map;
	Actor player;
	std::vector<AI> actorList;
public:
	Engine();
	~Engine();
	void Update(TCOD_key_t key);
	void Render();
	void makeGuidestones();
	void makePods(int podNum, int minPodSize, int maxPodSize);
};