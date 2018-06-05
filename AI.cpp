#include "Main.h"


AI::AI(int aitype)
{
	this->AITYPE = aitype;
}

AI::AI()
{
	this->AITYPE = 0;
}

AI::~AI()
{
	//path->~TCODPath();
}

void AI::Update(int nextTask, Actor * me)
{
	switch (nextTask)
	{
	case 1:					// Go Defensive
	{
		break;
	}	
	default :				// Follow Patrol
	{		
		Patrol(me);
		break;
	}
	}
}

int AI::Decision()
{
	return 0;
}

void AI::Patrol(Actor * me)
{	
	
}