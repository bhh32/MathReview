#include "GameManager.h"
#include "sfwdraw.h"
#include <iostream>

GameManager InitObjects()
{
	GameManager gameManager;

		// Initialize the player
		gameManager.player.sprite = sfw::loadTextureMap("../resources/marioBig.png", 21, 2);
		gameManager.player.transform.demension = vec2{ 50, 75 };
		gameManager.player.transform.position = vec2{ 10, 21 };
		gameManager.player.collider.box.extents = { .5f, .5f };
		gameManager.player.gravityCollider.box.extents = { 1.f, 1.f };
		gameManager.player.isGrounded = false;
		gameManager.player.isOnPlatform = false;
		gameManager.player.rigidbody.drag = 3.f;
		gameManager.player.sprite.animTimer = 1.f;

		// Initialize the ground
		gameManager.ground.sprite = sfw::loadTextureMap("../resources/ground.png");
		gameManager.ground.transform.demension = { 2000, 500 };
		gameManager.ground.transform.position = { 400, -200 };
		gameManager.ground.collider.box.extents = { .42f, .42f };

		// Intialize Static Platforms
		for (int i = 0; i < 3; ++i)
			gameManager.staticPlatforms[i].InitStaticPlatforms(gameManager.staticPlatforms[i]);

		// Specific Stats of Each Static Platform
		gameManager.staticPlatforms[0].sprite = sfw::loadTextureMap("../resources/wall.png");
		gameManager.staticPlatforms[0].transform.demension = vec2{ 150, 200 };
		gameManager.staticPlatforms[0].transform.position = vec2{ 500, 40 };

		gameManager.staticPlatforms[1].sprite = gameManager.staticPlatforms[0].sprite;
		gameManager.staticPlatforms[1].transform.demension = vec2{ 150, 50 };
		gameManager.staticPlatforms[1].transform.position = vec2{ 0, 350 };

		gameManager.staticPlatforms[2].sprite = gameManager.ground.sprite;
		gameManager.staticPlatforms[2].transform.demension = vec2{ 150, 50 };
		gameManager.staticPlatforms[2].transform.position = vec2{ 800, 500 };

		// Initialize Horizontal Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.horizontalPlatforms[i].InitHorizontalPlatforms(gameManager.horizontalPlatforms[i]);

		// Specific Stats of Each Horizontal Moving Platform
		gameManager.horizontalPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.horizontalPlatforms[0].transform.position = vec2{ 600, 250 };
		gameManager.horizontalPlatforms[0].minPosX = 600.f;
		gameManager.horizontalPlatforms[0].maxPosX = 750.f;		
		

		// General Initialization of upRight Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.upRightPlatforms[i].InitUpRightPlatforms(gameManager.upRightPlatforms[i]);

		// Specific Stats of Each upRight Moving Platform
		gameManager.upRightPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.upRightPlatforms[0].transform.position = vec2{ 25, 30 };
		gameManager.upRightPlatforms[0].minPosX = 110.f;
		gameManager.upRightPlatforms[0].maxPosX = 275.f;

		// General Initialization of upLeft Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.upLeftPlatforms[i].InitUpLeftPlatforms(gameManager.upLeftPlatforms[i]);

		// Specific Stats of Each UpLeft Moving Platform
		gameManager.upLeftPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.upLeftPlatforms[0].transform.position = vec2{ 520, 280 };
		gameManager.upLeftPlatforms[0].minPosX = 485.f;
		gameManager.upLeftPlatforms[0].maxPosX = 600.f;

		// General Initialization of Vertical Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.verticalPlatforms[i].InitVerticalPlatforms(gameManager.verticalPlatforms[i]);

		// Specific Stats of each vertical moving platform
		gameManager.verticalPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.verticalPlatforms[0].transform.position = vec2{ 500, 180 };
		gameManager.verticalPlatforms[0].minPosY = 180.f;
		gameManager.verticalPlatforms[0].maxPosY = 250.f;

	return gameManager;
}

// Main Game Loop calls all other functions needed for the game
void GameLoop()
{
	sfw::initContext();

	GameManager gameManager;
	gameManager = InitObjects();


	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();
		dt = dt > 1 ? 1 : dt;

		// Update Everything

		/* Update Player and Platform Movement */
		PollControllers(gameManager.player, gameManager.staticPlatforms, gameManager.horizontalPlatforms, 
			gameManager.verticalPlatforms, gameManager.upLeftPlatforms, gameManager.upRightPlatforms, dt);

		// Handle Collision
		Collision(gameManager.player, gameManager.staticPlatforms, gameManager.horizontalPlatforms,
			gameManager.verticalPlatforms, gameManager.upLeftPlatforms, gameManager.upRightPlatforms, gameManager.ground);

		// Draw Everything
		
		/* Draw Player and Platforms */
		Draw(gameManager.player, gameManager.staticPlatforms, gameManager.horizontalPlatforms, 
			gameManager.verticalPlatforms, gameManager.upLeftPlatforms, gameManager.upRightPlatforms, gameManager.ground, dt);	
	}

}

// Helper Function to get the bottom of the player's transform
float GetPlayerBottom(Player &player)
{
	return player.transform.position.y - (player.transform.demension.y / 2);
}

// Poll All Controllers
void PollControllers(Player &player, Platform *staticPlatforms, Platform *horizontalPlatforms, Platform * verticalPlatforms, Platform * leftUpPlatforms, Platform * rightUpPlatforms, float dt)
{
	// Poll the player controller and Integrate
	player.controller.Poll(player);
	player.rigidbody.Integrate(player.transform, dt);

	// Poll the Moving Platforms
	for (int i = 0; i < 2; ++i)
	{
		// Update the Horizontal Moving Platforms
		horizontalPlatforms[i].controller.PollHorizontalPlatform(horizontalPlatforms, horizontalPlatforms[i].minPosX, horizontalPlatforms[i].maxPosX, horizontalPlatforms[i].speed, i);
		horizontalPlatforms[i].rigidbody.Integrate(horizontalPlatforms[i].transform, dt);

		// Update the UpRight Moving Platforms
		rightUpPlatforms[i].controller.PollDiagonalUpRightPlatform(rightUpPlatforms, rightUpPlatforms[i].minPosX, rightUpPlatforms[i].maxPosX, rightUpPlatforms[i].speed, i);
		rightUpPlatforms[i].rigidbody.Integrate(rightUpPlatforms[i].transform, dt);

		leftUpPlatforms[i].controller.PollDiagonalUpLeftPlatform(leftUpPlatforms, leftUpPlatforms[i].minPosX, leftUpPlatforms[i].maxPosX, leftUpPlatforms[i].speed, i);
		leftUpPlatforms[i].rigidbody.Integrate(leftUpPlatforms[i].transform, dt);

		// Update the Vertical Moving Platforms
		verticalPlatforms[i].controller.PollVerticalPlatform(verticalPlatforms, verticalPlatforms[i].minPosY, verticalPlatforms[i].maxPosY, verticalPlatforms[i].speed, i);
		verticalPlatforms[i].rigidbody.Integrate(verticalPlatforms[i].transform, dt);

	}
}

// Draw Everything
void Draw(Player &player, Platform* staticPlatforms, Platform* horizontalPlatforms, 
	Platform* verticalPlatforms, Platform* leftUpPlatforms, Platform* rightUpPlatforms, Wall &ground,
	float dt)
{
	// Draw The Ground
	ground.sprite.Draw(ground.transform);

	// Draw and Update the player animation
	player.sprite.DrawAnim(player.transform, player.isGrounded, dt);
	
	// Draw The Moving Platforms
	for (int i = 0; i < 5; ++i)
	{
		if(staticPlatforms[i].sprite.handle != -1)
			staticPlatforms[i].sprite.Draw(staticPlatforms[i].transform);
		if(horizontalPlatforms[i].sprite.handle != -1)
			horizontalPlatforms[i].sprite.Draw(horizontalPlatforms[i].transform);
		if(rightUpPlatforms[i].sprite.handle != -1)
			rightUpPlatforms[i].sprite.Draw(rightUpPlatforms[i].transform);
		if (leftUpPlatforms[i].sprite.handle != -1)
			leftUpPlatforms[i].sprite.Draw(leftUpPlatforms[i].transform);
		if(verticalPlatforms[i].sprite.handle != -1)
			verticalPlatforms[i].sprite.Draw(verticalPlatforms[i].transform);
	}
}

// Collision Resolution
void Collision(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, Wall &ground)
{
	// Set the current parent to null
	player.transform.setParent();
	// Set grounded to false (ensures gravity works properly)
	player.isGrounded = false;
	// Set that the player isn't on a platform
	player.isOnPlatform = false;

	// Check for collision with all static platforms
	for (int i = 0; i < 5; ++i)
	{
		// Get the current postion of the bottom of the player
		float playerBottom = GetPlayerBottom(player);

		// Current right Up moving platform's top - 10 pixels to ensure grounding properly works
		float platformTop = staticPlatforms[i].transform.position.y + (staticPlatforms[i].transform.demension.y / 2) - 10.f;

		if (DoCollision(player, staticPlatforms[i], 0.f) && playerBottom > platformTop)
		{
			player.transform.setParent(&staticPlatforms[i].transform);
			player.isGrounded = true;
			player.isOnPlatform = true;
			break;
		}
	}

	// Check for collision with all horizontal moving platforms
	for (int i = 0; i < 5; ++i)
	{
		// Get the current position of the bottom of the player
		float playerBottom = GetPlayerBottom(player);

		// Check to see if the player is colliding with the platform AND they are on top of it
		if (DoCollision(player, horizontalPlatforms[i], 0.f) &&	playerBottom > horizontalPlatforms[i].transform.position.y)
		{
			player.transform.setParent(&horizontalPlatforms[i].transform);
			player.isGrounded = true;
			player.isOnPlatform = true;
			break;
		}
	}

	// Check for collision with all right up diagnonal moving platforms
	for (int i = 0; i < 5; ++i)
	{
		// Get the current postion of the bottom of the player
		float playerBottom = GetPlayerBottom(player);

		// Check to see if the player is colliding with the platform AND they are on top of it
		float platformTop = rightUpPlatforms[i].transform.position.y + (rightUpPlatforms[i].transform.demension.y / 2);

		if (DoCollision(player, rightUpPlatforms[i], 0.f) && playerBottom > platformTop)
		{
				player.transform.setParent(&rightUpPlatforms[i].transform);
				player.isGrounded = true;
				player.isOnPlatform = true;
				break;
		}
	}
	
	// Check for collision with all vertical moving platforms
	for (int i = 0; i < 5; ++i)
	{
		// Get the current postion of the bottom of the player
		float playerBottom = GetPlayerBottom(player);
		
		// Check to see if the player is colliding with the platform AND they are on top of it
		if (DoCollision(player, verticalPlatforms[i], 0.f) && playerBottom > verticalPlatforms[i].transform.position.y)
		{
   			player.transform.setParent(&verticalPlatforms[i].transform);
			player.isGrounded = true;
			player.isOnPlatform = true;
			break;
		}
	}

	// Check for collision with the ground
	if (DoCollision(player, ground, 0.f))
	{
		                                         // Here as a place holder for the gravity test fucntion to work
			GravityTestCollision(player, ground, horizontalPlatforms[0]);
			player.isGrounded = true;
			player.isOnPlatform = false;
	}

	// Check to see if the player is in the air...
	if (!player.isGrounded)
		// ... if they are turn gravity back on
		player.gravity = -9.8f;
}
