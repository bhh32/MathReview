#include "sfwdraw.h"
#include "Level.h"


int main()
{

	sfw::initContext();

	// Create the level object and Init the level
	Level level1;
	level1.InitLevel();

	while (sfw::stepContext())
	{
		// Update Stuff
		level1.Update();

		// Draw Stuff
		level1.Draw();
	}

	sfw::termContext();

	return 0;
}