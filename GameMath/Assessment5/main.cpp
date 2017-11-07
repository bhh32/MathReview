#include "sfwdraw.h"
#include "DrawShape.h"
#include "Objects.h"


#include <iostream>


int main()
{
	sfw::initContext();

	Player player;
	player.sprite = sfw::loadTextureMap("../resources/Mario.png", 2, 8);
	player.transform.demension = vec2{ 19, 37 };
	player.transform.position = vec2{ 400, 300 };
	player.collider.box.extents = { .5, .5 };
	player.isGrounded = false;
	player.isOnPlatform = false;

	player.rigidbody.drag = 0;

	Platform staticPlatforms[10];

	
	// General Initialization of Horizontal Moving Platforms
	Platform horizontalPlatforms[5];
	for (int i = 0; i < 5; ++i)
		horizontalPlatforms[i].InitHorizontalPlatforms(horizontalPlatforms[i]);

	// Specific Stats of Each Horizontal Moving Platform
	horizontalPlatforms[0].transform.demension = vec2{ 88, 18 };
	horizontalPlatforms[0].transform.position = vec2{ 200, 45 };
	horizontalPlatforms[0].minPosX = 200.f;
	horizontalPlatforms[0].maxPosX = 300.f;

	horizontalPlatforms[1].transform.demension = vec2{ 38, 8 };
	horizontalPlatforms[1].transform.position = vec2{ 600, 300 };
	horizontalPlatforms[1].minPosX = 600.f;
	horizontalPlatforms[1].maxPosX = 750.f;

	// General Initialization of upRight Moving Platforms
	Platform upRightPlatforms[5];
	for (int i = 0; i < 5; ++i)
		upRightPlatforms[i].InitUpRightPlatforms(upRightPlatforms[i]);

	// Specific Stats of Each upRight Moving Platform
	upRightPlatforms[0].transform.demension = vec2{ 88, 18 };
	upRightPlatforms[0].transform.position = vec2{ 10,50 };
	upRightPlatforms[0].minPosX = 45.f;
	upRightPlatforms[0].maxPosX = 150.f;

	// General Initialization of upLeft Moving Platforms
	/*Platform upLeftPlatforms[5];
	for (int i = 0; i < 5; ++i)
		upLeftPlatforms[i].InitUpLeftPlatforms(upLeftPlatforms[i]);*/

	// Init of the ground object
	Wall ground;
	ground.sprite = sfw::loadTextureMap("../resources/wall.png");
	ground.transform.demension = { 800, 20 };
	ground.transform.position = { 400, 0 };
	ground.collider.box.extents = { .5, .5 };

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		// Update Stuff

		/* Update Player Movement */
		player.controller.Poll(player);
		player.rigidbody.Integrate(player.transform, dt);
		/* Update Platform Movement */
		for (int i = 0; i < 2; ++i)
		{
			// Update the Horizontal Moving Platforms
			horizontalPlatforms[i].controller.PollHorizontalPlatform(horizontalPlatforms, horizontalPlatforms[i].minPosX, horizontalPlatforms[i].maxPosX, horizontalPlatforms[i].speed, i);
			horizontalPlatforms[i].rigidbody.Integrate(horizontalPlatforms[i].transform, dt);

			upRightPlatforms[i].controller.PollDiagonalUpRightPlatform(upRightPlatforms, upRightPlatforms[i].minPosX, upRightPlatforms[i].maxPosX,upRightPlatforms[i].speed, i);
			upRightPlatforms[i].rigidbody.Integrate(upRightPlatforms[i].transform, dt);
		}
		
		// Draw Stuff
		ground.sprite.Draw(ground.transform);
		player.sprite.Draw(player.transform);

		for (int i = 0; i < 2; ++i)
		{
			horizontalPlatforms[i].sprite.Draw(horizontalPlatforms[i].transform);
			upRightPlatforms[i].sprite.Draw(upRightPlatforms[i].transform);
		}

		DrawAABB(ground.collider.GetGlobalBox(ground.transform),BLUE);
		DrawAABB(player.collider.GetGlobalBox(player.transform), MAGENTA);

		// Collision Resolution
		if (DoCollision(player, horizontalPlatforms[0], 0.f))
		{
			player.isGrounded = true;
			player.rigidbody.velocity.x = horizontalPlatforms[0].rigidbody.velocity.x;
		}
		else
		{
			player.isGrounded = false;
		}

		if (DoCollision(player, ground, .0f))
		{
			player.isGrounded = true;
		}
		else
			player.isGrounded = false;

		
		std::cout << player.rigidbody.velocity.x << std::endl;
	}
	
	sfw::termContext();

	return 0;	
}