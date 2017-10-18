#include "sfwdraw.h"
#include "Camera.h"
#include "Player.h"


int main()
{
	sfw::initContext();

	Camera mainCamera;
	Player player;

	player.playerTransform.e_parent = &mainCamera.cameraTransform;

	player.playerTransform.position = vec2{ 400, 300 };
	player.playerTransform.demension = vec2{ 20, 40 };

	while (sfw::stepContext())
	{
		mainCamera.CameraDraw();
		player.Draw();
	}

	return 0;
}