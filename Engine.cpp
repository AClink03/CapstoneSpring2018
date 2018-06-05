#pragma once
#include "Main.h"

Engine::Engine()
{
	// init game window
	TCODConsole::initRoot(80, 50, "Prototype", false);

	// init map
	map = new Map(80,50);
	// make guidestones
	map->makeLandmarks(4);
	
	// init player
	player.loc = new Location(40, 25, 10, 1);
	player.rend.ch = '@';
	player.rend.col = TCODColor::white;
	// player.tp = &map->tiles[player.loc->x][player.loc->y];

	/*
		MISSION STUFF HERE
		-	eventually, all of these will have nice clean functions so it doesn't look like
			I hacked this nonsense together so I could go home early to pet my dog and punch rats.
		-	Mission consists of:
			- Objective
			- Guidestone Waypoints
			- NPCs (Hostile, Friendly, Neutral, etc.)
			- Weather? (I mean, a cloud is an actor I can't kill, right?)
	*/

	

	// make pods
	
	/*tempBandit.ai.path->compute
	(
		tempBandit.loc->x, 
		tempBandit.loc->y, 
		tempBandit.ai.waypoints[tempBandit.ai.wpt].x, 
		tempBandit.ai.waypoints[tempBandit.ai.wpt].y
	);*/	
}

Engine::~Engine()
{
	delete map;
}

void Engine::Update(TCOD_key_t key)
{
	// update player
	player.Update(key);
	// update bandits

	// update friendlies

	// update mission

}

void Engine::Render()
{
	TCODConsole::root->clear();	
	map->mRender();
	player.pRender();
	/*for (int x = 0; x < aList.capacity(); x++)
	{
		aList[x].pRender();
	}*/

}

void Engine::makePods(int podNum, int minPodSize, int maxPodSize)
{
	for (int x = 0; x < podNum; x++)
	{

	}
}
