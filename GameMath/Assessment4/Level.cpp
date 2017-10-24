#include "Level.h"
#include "sfwdraw.h"
#include <iostream>

Level::Level()
{
	ground = sfw::loadTextureMap("res/quickGround.png");
	sky = sfw::loadTextureMap("res/sky.png");
	
	
	// Platform Transform Setups         Position       Demension(Scale) Rotation Angle
	platforms[0].transform = Transform(vec2{ 128, 15 }, vec2{ 256, 25 }, 0.f);
	platforms[1].transform = Transform(vec2{ 400, 0 }, vec2{ 256, 18 }, 0.f);
	platforms[2].transform = Transform(vec2{ 690, 10 }, vec2{ 256, 25 }, 0.f);
	platforms[3].transform = Transform(vec2{ 693, 40 }, vec2{ 128, 35 }, 0.f);
	platforms[4].transform = Transform(vec2{ 575, 45 }, vec2{ 256, 115 }, 0.f);
	platforms[5].transform = Transform(vec2{ 295, 45 }, vec2{ 256, 115 }, 0.f);
	platforms[6].transform = Transform(vec2{ 310, 45 }, vec2{ 128, 200 }, 0.f);
	platforms[7].transform = Transform(vec2{ 450, 45 }, vec2{ 256, 315 }, 0.f);


	// Set the platforms ground height
	platforms[0].SetGroundHeight(platforms[0].transform.position.y + (platforms[0].transform.demension.y / 2));
	platforms[1].SetGroundHeight(platforms[1].transform.position.y + (platforms[1].transform.demension.y / 2));
	platforms[2].SetGroundHeight(platforms[2].transform.position.y + (platforms[2].transform.demension.y / 2));
	platforms[3].SetGroundHeight(platforms[3].transform.position.y + (platforms[3].transform.demension.y / 2));
	platforms[4].SetGroundHeight(platforms[4].transform.position.y + (platforms[4].transform.demension.y / 2));
	platforms[5].SetGroundHeight(platforms[5].transform.position.y + (platforms[5].transform.demension.y / 2));
	platforms[6].SetGroundHeight(platforms[6].transform.position.y + (platforms[6].transform.demension.y / 2));
	platforms[7].SetGroundHeight(platforms[7].transform.position.y + (platforms[7].transform.demension.y / 2));
	

	// Set the left and right bounds of the platforms
	platforms[0].SetBounds(platforms[0].transform.position.x - (platforms[0].transform.demension.x / 2), platforms[0].transform.position.x + (platforms[0].transform.demension.x / 2));
	platforms[1].SetBounds(platforms[1].transform.position.x - (platforms[1].transform.demension.x / 2), platforms[1].transform.position.x + (platforms[1].transform.demension.x / 2));
	platforms[2].SetBounds(platforms[2].transform.position.x - (platforms[2].transform.demension.x / 2), platforms[2].transform.position.x + (platforms[2].transform.demension.x / 2));
	platforms[3].SetBounds(platforms[3].transform.position.x - (platforms[3].transform.demension.x / 2), platforms[3].transform.position.x + (platforms[3].transform.demension.x / 2));
	platforms[4].SetBounds(platforms[4].transform.position.x - (platforms[4].transform.demension.x / 2), platforms[4].transform.position.x + (platforms[4].transform.demension.x / 2));
	platforms[5].SetBounds(platforms[5].transform.position.x - (platforms[5].transform.demension.x / 2), platforms[5].transform.position.x + (platforms[5].transform.demension.x / 2));
	platforms[6].SetBounds(platforms[6].transform.position.x - (platforms[6].transform.demension.x / 2), platforms[6].transform.position.x + (platforms[6].transform.demension.x / 2));
	platforms[7].SetBounds(platforms[7].transform.position.x - (platforms[7].transform.demension.x / 2), platforms[7].transform.position.x + (platforms[7].transform.demension.x / 2));
}

void Level::InitLevel()
{
	groundHeight = platforms[1].GetGroundHeight();
	player.InitPiece();
	player.SetGroundHeight(groundHeight);
}

void Level::Update()
{
	// Update the ground height
	std::cout << "groundHeight: " << groundHeight << std::endl;
	
	
	if(player.GetGroundHeight() != groundHeight)
		player.SetGroundHeight(groundHeight);

	// Check for which platform the player is on or most likely to land on
	for (int i = 0; i < 10; ++i)
	{
		if (player.pieceTransform.position.y > platforms[i].GetGroundHeight() && player.pieceTransform.position.x >= platforms[i].GetBounds().x && player.pieceTransform.position.x <= platforms[i].GetBounds().y)
			groundHeight = platforms[i].GetGroundHeight();
	}

	// Update the player
	
	player.Update();
	
}

void Level::Draw()
{
	// Draw the background
	sfw::drawTexture(sky, 400, 300, 800, 700);
	drawObject.DrawTexture(ground, platforms[7].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[4].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[6].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[5].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[0].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[1].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[2].transform.GetGlobalTransform());
	drawObject.DrawTexture(ground, platforms[3].transform.GetGlobalTransform());
	

	// Draw The player
	player.Draw();
	
}
