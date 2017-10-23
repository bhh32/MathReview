#include "Level.h"
#include "sfwdraw.h"

Level::Level()
{
	ground = sfw::loadTextureMap("res/quickGround.png");
	sky = sfw::loadTextureMap("res/sky.png");

	
}

void Level::InitLevel(Piece &player)
{
	this->player = player;
}

void Level::Update()
{
	// Update the player
	player.Update();
}

void Level::Draw()
{
	
	

	// Draw the background
	sfw::drawTexture(sky, 400, 300, 800, 700);
	sfw::drawTexture(ground, 400, 0, 256, 18);
	sfw::drawTexture(ground, 690, 10, 256, 25);
	sfw::drawTexture(ground, 128, 15, 256, 25);

	// Draw The player
	player.Draw();
	
}
