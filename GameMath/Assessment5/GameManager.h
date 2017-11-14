#pragma once

#include "Objects.h"


struct GameManager
{
	Player player;
	Platform staticPlatforms[10];
	Platform horizontalPlatforms[5];
	Platform upRightPlatforms[5];
	Platform upLeftPlatforms[5];
	Platform verticalPlatforms[5];
	Wall ground;
};
GameManager InitObjects();
void GameLoop();
float GetPlayerBottom(Player &player);
void PollControllers(Player &player, Platform* staticPlatforms, 
	Platform* horizontalPlatforms, Platform* verticalPlatforms, 
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, float dt);

void Draw(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, Wall &ground, 
	float dt);

void Collision(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, Wall &ground);