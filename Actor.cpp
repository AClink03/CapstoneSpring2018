#pragma once
#include "Main.h"

Actor::Actor(Location Loc, Render Rend, Tile * Tp)
{
	this->loc = &Loc;
	this->rend = Rend;
	this->tp = Tp;
}

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::pRender() const
{
	TCODConsole::root->setChar(this->loc->x, this->loc->y, this->rend.ch);
	TCODConsole::root->setCharForeground(this->loc->x, this->loc->y, this->rend.col);
	switch (this->loc->h)
	{
	case 1:
	{
		TCODConsole::root->putCharEx(this->loc->x, this->loc->y - 1, TCOD_CHAR_VLINE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 2:
	{
		TCODConsole::root->putCharEx(this->loc->x + 1, this->loc->y - 1, TCOD_CHAR_NE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 3:
	{
		TCODConsole::root->putCharEx(this->loc->x + 1, this->loc->y, TCOD_CHAR_HLINE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 4:
	{
		TCODConsole::root->putCharEx(this->loc->x + 1, this->loc->y + 1, TCOD_CHAR_SE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 5:
	{
		TCODConsole::root->putCharEx(this->loc->x, this->loc->y + 1, TCOD_CHAR_VLINE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 6:
	{
		TCODConsole::root->putCharEx(this->loc->x - 1, this->loc->y + 1, TCOD_CHAR_SW, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 7:
	{
		TCODConsole::root->putCharEx(this->loc->x - 1, this->loc->y, TCOD_CHAR_HLINE, TCODColor::red, TCODColor::yellow);
		break;
	}
	case 8:
	{
		TCODConsole::root->putCharEx(this->loc->x - 1, this->loc->y - 1, TCOD_CHAR_NW, TCODColor::red, TCODColor::yellow);
		break;
	}
	}
}

void Actor::Update(TCOD_key_t key)
{
	Location tLoc;
	/*
	Entry point for the decision making for the player
	TCOD_key_t key is the object that holds the key pressed

	key.vk represents the physical key on the keyboard
	key.c is the printable character of the key pressed, if the that was pressed
	corresponds to a printable character
	key.pressed is true if the key is pressed, and false if released (useful for clutch
	keys)

	*/
	switch (key.vk)
	{
	case TCODK_KP5:			// Pass turn
	{
		findTile(this->loc->h, this->loc->h);
		break;
	}
	case TCODK_LEFT:		// slip left
	{
		findTile(moveHelper(1), this->loc->h);
		break;
	}
	case TCODK_RIGHT:		// slip right
	{
		findTile(moveHelper(3), this->loc->h);
		break;
	}
	case TCODK_KP4:			// combat turn left
	{
		findTile(moveHelper(1), moveHelper(1));
		break;
	}
	case TCODK_KP6:			// combat turn right
	{
		findTile(moveHelper(3), moveHelper(3));
		break;
	}
	case TCODK_KP1:			// break turn left
	{
		findTile(moveHelper(1), moveHelper(1));
		this->loc->h = moveHelper(1);
		break;
	}
	case TCODK_KP3:			// break turn right
	{
		findTile(moveHelper(3), moveHelper(3));
		this->loc->h = moveHelper(3);
		break;
	}
	case TCODK_KP7:			// bank turn left
	{
		findTile(this->loc->h, moveHelper(1));
		break;
	}
	case TCODK_KP9:			// bank turn right
	{
		findTile(this->loc->h, moveHelper(3));
		break;
	}
	}
}

void Actor::findTile(int h, int nh)
{
	int tx, ty;
	tx = this->loc->x;
	ty = this->loc->y;

	switch (h)
	{
	case 1:
	{
		// Heading North
		ty--;
		break;
	}
	case 2:
	{
		// Heading NorthEast
		ty--;
		tx++;
		break;
	}
	case 3:
	{
		// Heading East
		tx++;
		break;
	}
	case 4:
	{
		// Heading SouthEast
		ty++;
		tx++;
		break;
	}
	case 5:
	{
		// Heading South
		ty++;
		break;
	}
	case 6:
	{
		// Heading SouthWest
		ty++;
		tx--;
		break;
	}
	case 7:
	{
		// Heading West
		tx--;
		break;
	}
	case 8:
	{
		// Heading NorthWest
		ty--;
		tx--;
		break;
	}
	}
	Move(tx, ty, nh);
}

void Actor::Move(int x, int y, int eh)
{
	// Upper left is 0,0, lowest-Right is width-1, height-1

	// crude pointing UI for heading/Gun/Radar	
	
	this->loc->x = x;
	this->loc->y = y;
	this->loc->h = eh;	
}

int Actor::moveHelper(int md)
{
	// if md = 1, turn left
	// if md = 2, move forward
	// if md = 3, move right

	int tH = this->loc->h;
	if (md == 1)
	{
		if (tH == 1)
		{
			tH = 8;
		}
		else
		{
			tH--;
		}
	}
	else if (md == 2)
	{
		// probably don't need this right now, may change later
	}
	else if (md == 3)
	{
		if (tH == 8)
		{
			tH = 1;
		}
		else
		{
			tH++;
		}
	}
	return tH;
}

int NewHeading()
{

	return 0;
}

void ChangeHeading()
{

}

void Move()
{
	
}