#pragma once
class Pilot
{
	/*
		Calm (High value == Good)
			-	staying cool under fire, the higher this number, the higher chance of moving up the 
				priority list for making decisions. Reflects training level of the pilot, and experience
				keeping them on task. Used to resist negative changes to Status.
				EX: A pilot with High Calm goes Defensive, instead of continuing Offensive when
				attacked, resulting in the Pilot keeping his plane in the air longer due to acute
				lack of hitpoint syndrome.
		Focus (aka Tunnel Vision, High value == Bad)
			-	Buildup of willpower to 'keep to the plan'. Someone with high focus will resist the
				urge to change Priorities, even when beneficial.
				EX: a pilot with High Focus may, even through good training, ignore a launch warning
				to finish off a low health target. 
	*/
	int calm, focus;
public:
	Pilot();
	~Pilot();
};

