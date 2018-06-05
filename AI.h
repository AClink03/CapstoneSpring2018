#pragma once

class Actor;
class Waypoint;

class AI
{
private:

public:
	Actor aiActor;							// If Scott sees this he may actually kill me
	int AITYPE;								// what kind of AI is it
	Status status;							// what state is the AI in
	std::vector<Waypoint> waypoints;		// list of waypoints to follow
	int wpt;								// what waypoint am I heading towards?
	Location * target;						// the last location of a known hostile/ current location of hostile targeted
	bool fl;								// is this actor a 'flight leader'
	Actor * leader;							// pointer to Actor's flight leader, NULL if fl == true
	int formID;								// what number in the formation is the Actor (fl == 1)
	bool advantage;							// is actor in an advantageous position
	bool firstWP = true;
	int step = 0;

	AI(int aitype);
	/*
	Nothing	=	0
	Player	=	1
	Friendly=	2
	Hostile	=	3
	Neutral	=	4
	Missile	=	5
	*/
	AI();
	~AI();

	void Update(int nextTask, Actor * me);				// AI does a thing based on status
	int Decision();										// Change status

	/*
		Status Decision Functions:
		-	These are in order of precedence, with self presevation being most important
			--	Defensive:
					Oh shit, I'm being attacked and don't have advantage, go to defensive maneuvering
					and attempt to gain advantage over whatever is firing at me (if possible)
					OR
					I have advantage, but am actively being fired upon. Make a decision to
					Stay Offensive or break off attack to defend (weighted towards the latter)
			--	Offensive:
					I've got advantage and am not currently being turbo-murdered, lets kill this nerd I have
					advantage on
					OR 
					turbo-murder-aimed-at-me potential is negligible, 
					so I'm gonna shoot some missiles and guns at someone I have advantage on
			--	Chasing:
					I don't have advantage, but I'm aware of a hostile. Try to gain advantage of the
					enemy and move to fire weapons
					OR
					I have advantage, but PK is terrible. Try to raise the PK by maneuvering into better
					position
			--	Press:
					I have a target, and possibly advantage, but not in range to attack. Get in range
					and move to Offensive status
			--	Reaqcuire:
					I've lost all contact with a hostile, so I will go to their last position and
					try to reaquire			
			--	Follow:
					I've got sight on a hostile, but a friendly is taking the shot
					OR
					I've got no sight on hostiles, and I have a flight leader
					OR
					I've got no sight on hostiles, and are protecting/screening for another plane
			--	Patrol:
					I'm in no danger, I've detected no enemies, so I will fly my patrol path until
					one of those two things becomes true
	*/
	//void Defensive();						// Take defensive action against incoming fire, Highest Priority	
	void Patrol(Actor * me);				// Follow waypoints until something forces a change, Lowest Priority

	void shortPath();
	void flightPath();
};