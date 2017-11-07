#include "sfwdraw.h"
#include "DrawShape.h"
#include "Objects.h"


#include <iostream>


int main()
{
	sfw::initContext();

	Player player;
	player.sprite = sfw::loadTextureMap("../resources/marioBig.png", 21, 2);
	player.transform.demension = vec2{ 50, 75 };
	player.transform.position = vec2{ 400, 300 };
	player.collider.box.extents = { .5, .5 };
	player.isGrounded = false;
	player.isOnPlatform = false;

	player.rigidbody.drag = 0;
	player.sprite.animTimer = 1.f;
	/*player.sprite.InitAnimation(0, 20, .1f);*/

	Platform staticPlatforms[10];
	for (int i = 0; i < 10; ++i)
		staticPlatforms[i].InitStaticPlatforms(staticPlatforms[i]);

	staticPlatforms[0].sprite = sfw::loadTextureMap("../resources/wall.png");
	staticPlatforms[0].transform.demension = vec2{ 110, 200 };
	staticPlatforms[0].transform.position = vec2{ 500, 40 };


	// General Initialization of Horizontal Moving Platforms
	Platform horizontalPlatforms[5];
	for (int i = 0; i < 5; ++i)
		horizontalPlatforms[i].InitHorizontalPlatforms(horizontalPlatforms[i]);

	// Specific Stats of Each Horizontal Moving Platform
	horizontalPlatforms[0].transform.demension = vec2{ 88, 18 };
	horizontalPlatforms[0].transform.position = vec2{ 200, 45 };
	horizontalPlatforms[0].minPosX = 200.f;
	horizontalPlatforms[0].maxPosX = 300.f;

	horizontalPlatforms[1].transform.demension = vec2{ 88, 18 };
	horizontalPlatforms[1].transform.position = vec2{ 600, 300 };
	horizontalPlatforms[1].minPosX = 600.f;
	horizontalPlatforms[1].maxPosX = 750.f;

	// General Initialization of upRight Moving Platforms
	Platform upRightPlatforms[5];
	for (int i = 0; i < 5; ++i)
		upRightPlatforms[i].InitUpRightPlatforms(upRightPlatforms[i]);

	// Specific Stats of Each upRight Moving Platform
	upRightPlatforms[0].transform.demension = vec2{ 88, 18 };
	upRightPlatforms[0].transform.position = vec2{ 30,50 };
	upRightPlatforms[0].minPosX = 110.f;
	upRightPlatforms[0].maxPosX = 220.f;

	// General Initialization of upLeft Moving Platforms
	Platform upLeftPlatforms[5];
	for (int i = 0; i < 5; ++i)
		upLeftPlatforms[i].InitUpLeftPlatforms(upLeftPlatforms[i]);

	// Specific Stats of Each UpLeft Moving Platform
	/*upLeftPlatforms[0].transform.demension = vec2{ 88, 18 };
	upLeftPlatforms[0].transform.position = vec2{ 600, 80 };*/

	Platform verticalPlatforms[5];
	for (int i = 0; i < 5; ++i)
		verticalPlatforms[i].InitVerticalPlatforms(verticalPlatforms[i]);

	// Specific Stats of each vertical moving platform
	verticalPlatforms[0].transform.demension = vec2{ 88, 18 };
	verticalPlatforms[0].transform.position = vec2{ 500, 180 };
	verticalPlatforms[0].minPosY = 180.f;
	verticalPlatforms[0].maxPosY = 300.f;

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

			// Update the UpRight Moving Platforms
			upRightPlatforms[i].controller.PollDiagonalUpRightPlatform(upRightPlatforms, upRightPlatforms[i].minPosX, upRightPlatforms[i].maxPosX,upRightPlatforms[i].speed, i);
			upRightPlatforms[i].rigidbody.Integrate(upRightPlatforms[i].transform, dt);

			// Update the Vertical Moving Platforms
			verticalPlatforms[i].controller.PollVerticalPlatform(verticalPlatforms, verticalPlatforms[i].minPosY, verticalPlatforms[i].maxPosY, verticalPlatforms[i].speed, i);
			verticalPlatforms[i].rigidbody.Integrate(verticalPlatforms[i].transform, dt);

		}
		
		// Draw Stuff
		
		player.sprite.DrawAnim(player.transform, player.isGrounded, dt);

		/* Draw Moving Platforms */
		for (int i = 0; i < 2; ++i)
		{
			staticPlatforms[i].sprite.Draw(staticPlatforms[i].transform);
			horizontalPlatforms[i].sprite.Draw(horizontalPlatforms[i].transform);
			upRightPlatforms[i].sprite.Draw(upRightPlatforms[i].transform);
			verticalPlatforms[i].sprite.Draw(verticalPlatforms[i].transform);
		}
		ground.sprite.Draw(ground.transform);

		// Collision Resolution
			if (DoCollision(player, staticPlatforms[0], 0.1f))
			{
				player.isGrounded = true;
			}
			else if (DoCollision(player, horizontalPlatforms[0], 0.1f))
			{
				player.isGrounded = true;
				if (!sfw::getKey('A') && !sfw::getKey('D'))
					player.rigidbody.velocity.x = horizontalPlatforms[0].rigidbody.velocity.x;
			}
			else if (DoCollision(player, horizontalPlatforms[1], 0.1f))
			{
				player.isGrounded = true;
				if (!sfw::getKey('A') && !sfw::getKey('D'))
					player.rigidbody.velocity.x = horizontalPlatforms[1].rigidbody.velocity.x;
			}
			else if (DoCollision(player, upRightPlatforms[0], 0.01f))
			{
				player.isGrounded = true;
				if (!sfw::getKey('A') && !sfw::getKey('D'))
				{
					player.rigidbody.velocity.x = upRightPlatforms[0].rigidbody.velocity.x;
				}
			}
			else if (DoCollision(player, verticalPlatforms[0], 0.01f))
			{
				player.isGrounded = true;
			}
			else
			{
				player.isGrounded = false;
			}
		if (DoCollision(player, ground, .01f))
		{
			player.isGrounded = true;
		}
	}
	
	sfw::termContext();

	return 0;	
}