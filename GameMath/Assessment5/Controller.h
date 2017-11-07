#pragma once

//#include "Transform.h"
#include "sfwdraw.h"
//#include "Objects.h"
//#include "Rigidbody.h"

class Platform;
class Player;
class Rigidbody;
class Transform;

// Poll for input and apply changes to the rigidbody
class PlayerController
{
public:
	void Poll(Player &player);
};

class PlatformController
{
public:
	void PollHorizontalPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx);

	void PollVerticalPlatform(Platform *platform, float minPosY, float maxPosY, float speed, int idx);

	void PollDiagonalUpRightPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx);

	void PollDiagonalUpLeftPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx);
};