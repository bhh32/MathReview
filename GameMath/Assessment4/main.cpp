#include <iostream>
#include "sfwdraw.h"
#include "Level.h"
#include "Piece.h"


int main()
{

	sfw::initContext();

	Level level1;
	level1.InitLevel();

	while (sfw::stepContext())
	{
		// Update Stuff
		level1.Update();

		// Draw Stuff
		level1.Draw();

		// Spawn Stuff
	}

	return 0;
}