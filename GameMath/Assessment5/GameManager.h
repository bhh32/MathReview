#pragma once

#include "Objects.h"


struct GameManager
{
	Player player;
	Goal goal;
	Platform staticPlatforms[10];
	Platform horizontalPlatforms[5];
	Platform upRightPlatforms[5];
	Platform upLeftPlatforms[5];
	Platform verticalPlatforms[5];
	Platform multiDirPlatforms[5];
	Wall ground;

	unsigned int string;
	unsigned int sky;
	unsigned int firework[8];
};
GameManager InitObjects();
void GameLoop();
float GetPlayerBottom(Player &player);
void PollControllers(Player &player, Platform* staticPlatforms, 
	Platform* horizontalPlatforms, Platform* verticalPlatforms, 
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, 
	Platform *multiDirPlatforms, float dt);

void Draw(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, 
	Platform *multiDirPlatforms, Wall &ground, Goal &goal,
	unsigned int string, unsigned int sky, unsigned int* firework, 
	float dt);

void Collision(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, 
	Platform *multiDirPlatforms, Wall &ground, Goal &goal);