#include "Main.h"

class Location;

Waypoint::Waypoint()
{
}

Waypoint::Waypoint(Location Loc, std::string Name)
{
	loc = Loc;
	name = Name;
}


Waypoint::~Waypoint()
{
}
