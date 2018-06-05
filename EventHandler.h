#pragma once
class EventHandler
{
public:
	EventHandler();
	~EventHandler();
	void static PlayerUpdate(TCOD_key_t key);
	void static NPCUpdate();

	void static MoveActor(Actor owner);
	void static ShootCannon(Actor owner, Actor target);
	void static FireMissile(Actor owner, Actor target);
};

