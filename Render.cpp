#include "Main.h"

Render::Render(TCODColor Col, int CH)
{
	this->col = Col;
	this->ch = CH;
}

Render::Render()
{
	this->ch = 0;
}

Render::~Render()
{
}
