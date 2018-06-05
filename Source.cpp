#include "Main.h"

using namespace std;

Engine engine;

int main()
{
	TCODConsole::setKeyboardRepeat(0, 0);
	engine.Render();
	TCODConsole::flush();

	while (!TCODConsole::isWindowClosed())
	{
		// wait for player input for update
		TCOD_key_t key;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		// put update here
		if (key.pressed)
		{
			engine.Update(key);
		}
		// put render here
		engine.Render();			
		// draw to screen
		TCODConsole::flush();		
	}
	return 0;
}