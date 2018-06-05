#pragma once


class Location;

class Waypoint
{
private:
	Location loc;
	std::string name;
public:
	Waypoint();
	Waypoint(Location Loc, std::string Name);
	~Waypoint();
};

