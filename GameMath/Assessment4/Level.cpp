#include "Level.h"
#include "sfwdraw.h"
#include <iostream>

Level::Level()
{
	ground = sfw::loadTextureMap("res/quickGround.png");
	sky = sfw::loadTextureMap("res/sky.png");
	


	/* Platform Identities:
	                        platform1 = center 
							platform2 = bottom right
							platform3 = bottom left
							platform4 = second level right
	*/
	
	// Platform Positions
	//platforms[0] = Transform{ vec2{ 400, 0 }, vec2{256, 18 } };
	platform2.position = vec2{ 690, 10 };
	platform3.position = vec2{ 128, 15 };
	platform4.position = vec2{ 693, 40 };
	platform5.position = vec2{ 575, 45 };

	// Platform Scales
	platform1.demension = vec2{ 256, 18 };
	platform2.demension = vec2{ 256, 25 };
	platform3.demension = vec2{ 256, 25 };
	platform4.demension = vec2{ 128, 35 };
	platform5.demension = vec2{ 256, 115 };

	
	
}

void Level::InitLevel(Piece &player)
{
	this->player = player;
}

void Level::Update()
{
	// Update the ground height
	std::cout << "groundHeight: " << player.groundHeight << std::endl;
	float platform4Left = (platform4.position.x - (platform4.demension.x / 2));
	float platform4Right = (platform4.position.x + (platform4.demension.x / 2) + 9);
	

	if (player.pieceTransform.position.x + 9 < platform3.position.x + (platform3.demension.x / 2) && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2)) // Left Bottom Corner Platform
		player.groundHeight = platform3.position.y + 20.f;
	else if (player.pieceTransform.position.x + 9 >= platform3.position.x + (platform3.demension.x / 2) && player.pieceTransform.position.x - 9 < platform1.position.x - (platform1.demension.x / 2) && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2))
		player.groundHeight = -200.f; // Hole between left and center platforms
	else if (player.pieceTransform.position.x + 9 >= platform1.position.x - (platform1.demension.x / 2) && player.pieceTransform.position.x + 9 <= platform1.position.x + (platform1.demension.x / 2) && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2)) // Center Bottom Platform
		player.groundHeight = platform1.position.y + 18.f;
	else if (player.pieceTransform.position.x + 9 >= platform1.position.x + (platform1.demension.x / 2) && player.pieceTransform.position.x - 9 <= platform2.position.x - (platform2.demension.x / 2) && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2)) // Hole between bottom center and bottom right platforms
		player.groundHeight = -200.f;
	else if (player.pieceTransform.position.x + 9 >= platform2.position.x - (platform2.demension.x / 2) && player.pieceTransform.position.x - 9 <= platform4.position.x - (platform4.demension.x / 2) && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2)) // Left part of bottom right platform and 2nd level right platform
	{
		player.groundHeight = platform3.position.y + 17.f;

		// Platform 4 Left Side Wall Collision
		if (player.pieceTransform.position.x + 9 >= platform4Left && player.pieceTransform.position.y < (platform4.position.y + platform4.demension.y / 2))
			player.pieceTransform.position.x = platform4Left - 9;
	}
	else if (player.pieceTransform.position.x - 9 >= platform4Left && player.pieceTransform.position.x + 9 <= platform4Right && player.pieceTransform.position.y < platform5.position.y + (platform5.demension.y / 2)) // 2nd level right platform
	{
		player.groundHeight = platform4.position.y + 25.f;

		
	}
	else if (player.pieceTransform.position.x - 9 > platform4Right) // Right side of bottom right platform
	{
		player.groundHeight = platform3.position.y + 17.f;

		// Platform 4 Right Side Wall Collision
		if (player.pieceTransform.position.x - 9 <= platform4Right + 2 && player.pieceTransform.position.y < (platform4.position.y - platform4.demension.y / 2))
			player.pieceTransform.position.x = platform4Right;	
	}
	
	if (player.pieceTransform.position.y - 9 >= platform5.position.y + (platform5.demension.y / 2))
		player.groundHeight = platform5.position.y + (platform5.demension.y / 2);

	// Update the player
	player.Update();
}

void Level::Draw()
{
	
	

	// Draw the background
	sfw::drawTexture(sky, 400, 300, 800, 700);	
	drawObject.DrawTexture(ground, platform5.GetGlobalTransform());
	drawObject.DrawTexture(ground, platform1.GetGlobalTransform());
	drawObject.DrawTexture(ground, platform2.GetGlobalTransform());
	drawObject.DrawTexture(ground, platform3.GetGlobalTransform());
	drawObject.DrawTexture(ground, platform4.GetGlobalTransform());
	

	// Draw The player
	player.Draw();
	
}
