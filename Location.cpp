#include "Main.h"


Location::Location(int x, int y, int alt, int h)
{
	this->x = x;
	this->y = y;
	this->alt = alt;
	this->h = h;
}

Location::Location()
{
}

Location::~Location()
{
}

void Location::setLoc(int x, int y, int alt, int h)
{
	this->x = x;
	this->y = y;
	this->alt = alt;
	this->h = h;
}
