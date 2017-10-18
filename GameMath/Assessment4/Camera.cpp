#include "Camera.h"
#include "sfwdraw.h"
#include <Windows.h>

Camera::Camera()
{
	cameraTransform.position = vec2{ 400, 300 };
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
	// Debug Draw
	DebugDraw(cameraTransform.GetGlobalTransform(), 40);
}

void Camera::DebugDraw(const mat3 &t, float drawing_scale)
{
	// Origin Position
	vec2 pos = t[2].xy;

	vec2 rightEP = pos + t[0].xy * drawing_scale;
	vec2 upEP = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, rightEP.x, rightEP.y, RED);
	sfw::drawLine(pos.x, pos.y, upEP.x, upEP.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}
