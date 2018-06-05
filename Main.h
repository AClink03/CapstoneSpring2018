#pragma once

#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

enum Status 
{
	Defensive,
	// NOTHING HIGHER THAN THIS I SWEAR TO GOD ANDREW

	// NOTHING LOWER THAN THIS I SWEAR TO GOD ANDREW
	Patrol
};
class Actor;

#include "libtcod.hpp"

#include "Location.h"
#include "Render.h"

#include "Map.h"


#include "Airframe.h"
#include "Pilot.h"
#include "Waypoint.h"
#include "Actor.h"
#include "AI.h"

#include "EventHandler.h"
#include "Engine.h"

extern Engine engine;