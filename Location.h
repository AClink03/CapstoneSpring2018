#pragma once

class Location
{
public:
	int x; // location on Map on x-axis
	int y; // location on Map on y-axis
	int alt; // altitude of object, if applicable
	int h; /* heading of the object, if applicable
		   North points to the top of the window, South towards the bottom, etc etc
		   N	=	1
		   NE	=	2
		   E	=	3
		   SE	=	4
		   S	=	5
		   SW	=	6
		   W	=	7
		   NW	=	8
		   n/a	=	0
		   */
	Location(int x, int y, int alt, int h);
	Location();
	~Location();

	void setLoc(int x, int y, int alt, int h);
};