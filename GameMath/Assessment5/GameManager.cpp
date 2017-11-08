#include "GameManager.h"
#include "sfwdraw.h"

GameManager InitObjects()
{
	GameManager gameManager;

		// Initialize the player
		gameManager.player.sprite = sfw::loadTextureMap("../resources/marioBig.png", 21, 2);
		gameManager.player.transform.demension = vec2{ 50, 75 };
		gameManager.player.transform.position = vec2{ 400, 300 };
		gameManager.player.collider.box.extents = { .5, .5 };
		gameManager.player.isGrounded = false;
		gameManager.player.rigidbody.drag = 0.f;
		gameManager.player.sprite.animTimer = 1.f;

		// Initialize the ground
		gameManager.ground.sprite = sfw::loadTextureMap("../resources/wall.png");
		gameManager.ground.transform.demension = { 800, 20 };
		gameManager.ground.transform.position = { 400, 0 };
		gameManager.ground.collider.box.extents = { .5, .5 };

		// Intialize Static Platforms
		for (int i = 0; i < 10; ++i)
			gameManager.staticPlatforms[i].InitStaticPlatforms(gameManager.staticPlatforms[i]);

		gameManager.staticPlatforms[0].sprite = sfw::loadTextureMap("../resources/wall.png");
		gameManager.staticPlatforms[0].transform.demension = vec2{ 110, 200 };
		gameManager.staticPlatforms[0].transform.position = vec2{ 500, 40 };

		// Initialize Horizontal Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.horizontalPlatforms[i].InitHorizontalPlatforms(gameManager.horizontalPlatforms[i]);

		// Specific Stats of Each Horizontal Moving Platform
		gameManager.horizontalPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.horizontalPlatforms[0].transform.position = vec2{ 200, 45 };
		gameManager.horizontalPlatforms[0].minPosX = 200.f;
		gameManager.horizontalPlatforms[0].maxPosX = 300.f;

		gameManager.horizontalPlatforms[1].transform.demension = vec2{ 88, 18 };
		gameManager.horizontalPlatforms[1].transform.position = vec2{ 600, 300 };
		gameManager.horizontalPlatforms[1].minPosX = 600.f;
		gameManager.horizontalPlatforms[1].maxPosX = 750.f;

		// General Initialization of upRight Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.upRightPlatforms[i].InitUpRightPlatforms(gameManager.upRightPlatforms[i]);

		// Specific Stats of Each upRight Moving Platform
		gameManager.upRightPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.upRightPlatforms[0].transform.position = vec2{ 30,50 };
		gameManager.upRightPlatforms[0].minPosX = 110.f;
		gameManager.upRightPlatforms[0].maxPosX = 220.f;

		// General Initialization of upLeft Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.upLeftPlatforms[i].InitUpLeftPlatforms(gameManager.upLeftPlatforms[i]);

		// Specific Stats of Each UpLeft Moving Platform
		gameManager.upLeftPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.upLeftPlatforms[0].transform.position = vec2{ 600, 80 };

		// General Initialization of Vertical Moving Platforms
		for (int i = 0; i < 5; ++i)
			gameManager.verticalPlatforms[i].InitVerticalPlatforms(gameManager.verticalPlatforms[i]);

		// Specific Stats of each vertical moving platform
		gameManager.verticalPlatforms[0].transform.demension = vec2{ 88, 18 };
		gameManager.verticalPlatforms[0].transform.position = vec2{ 500, 180 };
		gameManager.verticalPlatforms[0].minPosY = 180.f;
		gameManager.verticalPlatforms[0].maxPosY = 300.f;

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
	// Draw and Update the player animation
	player.sprite.DrawAnim(player.transform, player.isGrounded, dt);

	// Draw The Ground
	ground.sprite.Draw(ground.transform);

	// Draw The Moving Platforms
	for (int i = 0; i < 2; ++i)
	{
		staticPlatforms[i].sprite.Draw(staticPlatforms[i].transform);
		horizontalPlatforms[i].sprite.Draw(horizontalPlatforms[i].transform);
		rightUpPlatforms[i].sprite.Draw(rightUpPlatforms[i].transform);
		verticalPlatforms[i].sprite.Draw(verticalPlatforms[i].transform);
	}
}

// Collision Resolution
void Collision(Player &player, Platform* staticPlatforms,
	Platform* horizontalPlatforms, Platform* verticalPlatforms,
	Platform *leftUpPlatforms, Platform* rightUpPlatforms, Wall &ground)
{
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
	else if (DoCollision(player, rightUpPlatforms[0], 0.01f))
	{
		player.isGrounded = true;
		if (!sfw::getKey('A') && !sfw::getKey('D'))
		{
			player.rigidbody.velocity.x = rightUpPlatforms[0].rigidbody.velocity.x;
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
