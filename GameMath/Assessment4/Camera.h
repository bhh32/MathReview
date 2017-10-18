#pragma once

#include "Transform.h"
#include "vec2.h"

class Camera
{
public:
	Camera();

	Transform cameraTransform;
	float speed;
	float maxSpeed;

	void CameraUpdate();
	void CameraDraw();
};