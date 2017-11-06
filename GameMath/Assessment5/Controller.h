#pragma once

//#include "Transform.h"
#include "sfwdraw.h"
//#include "Objects.h"
//#include "Rigidbody.h"

class Platform;
class Rigidbody;
class Transform;

// Poll for input and apply changes to the rigidbody
class PlayerController
{
public:
	void Poll(Rigidbody *rb, const Transform *t);
};

class PlatformController
{
public:
	void PollHorizontalPlatform(Platform *platform, float minPosX, float maxPosX, float speed);

	void PollVerticalPlatform(Platform *platform, float minPosY, float maxPosY, float speed);

	void PollDiagonalUpRightPlatform(Platform *platform, float minPosX, float maxPosX, float speed);

	void PollDiagonalUpLeftPlatform(Platform *platform, float minPosX, float maxPosX, float speed);
};