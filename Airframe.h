#pragma once

class Airframe
{
	/*
		-	Luck
			-	How much health the plane has left; if struck when at or below 0, your luck has 
				'run out' and the plane is struck for catastrophic, or near catastrophic damage
		-	MissilesRemaining
			-	How many missiles are remaining in the weapons' stores
		-	MissilePK
			-	Combination of chance for the missile to hit
				AND
				How much damage a missile will do when it succssefully hits its mark
		-	LaunchSide
			-	Which side of the plane a missile will fire from. Alternates from left to right side
		-	CannonDamage
			-	Similar to MissilePK, only for the main cannon. Reduced by 50% multiplicitively 
				for every square the target being hit is away from the first
				(
					1 = 100%
					2 = 50%
					3 = 25%
					4 = 12%
					5 = 0%
				)
	*/
	int Luck;
	int MissilesRemaining;
	int MissilePK;
	bool LaunchSide;
	int CannonDamage;

	Airframe();
	~Airframe();
};