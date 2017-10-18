#include "Camera.h"
#include "sfwdraw.h"
#include <Windows.h>

Camera::Camera()
{
	cameraTransform.position = vec2{ 0, 0 };
	cameraTransform.globalPosition = cameraTransform.position;

	cameraTransform.demension = vec2{ 1, 1 };
	cameraTransform.angle = 0;
	cameraTransform.e_parent = nullptr;

	speed = 0.f;
	maxSpeed = 200.f;
}

void Camera::CameraUpdate()
{
	if (sfw::getKey('W') || sfw::getKey(VK_UP))
	{
		if (speed != maxSpeed)
			speed += 10.f;
		else
			speed = maxSpeed;
	}
}

void Camera::CameraDraw()
{
}
