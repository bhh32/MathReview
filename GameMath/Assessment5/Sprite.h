#pragma once

#include "vec2.h"
#include "Transform.h"
#include "sfwdraw.h"

class Sprite
{
public:
	int handle;
	int animMin;
	int animMax;
	float animTimer;
	float startTimer;
	int idx;
	vec2 dim;
	vec2 offset;

	Sprite(int a_handle = -1, float width = 1, float height = 1) : handle(a_handle), dim{ width, height }, offset{ 0, 0 }
	{
		idx = 0;
		animMin = 0;
		animMax = 0;
	}

	void Draw(const Transform &t, int idx = 0, const mat3 &cam = mat3::Identity())
	{
		mat3 M = cam * t.GetGlobalTransform() * Translate(offset) * Scale(dim);

		sfw::drawTextureMatrix3(handle, idx, WHITE, M.m);
	}

	void DrawAnim(const Transform &t, float dt, const mat3 &cam = mat3::Identity())
	{
		mat3 M = cam * t.GetGlobalTransform() * Translate(offset) * Scale(dim);
		if (sfw::getKey('A') && !sfw::getKey(' ') || sfw::getKey('D') && !sfw::getKey(' '))
		{
			animMin = 0;
			animMax = 3;
			UpdateAnim(dt);
		}
		else
			idx = 0;
		sfw::drawTextureMatrix3(handle, idx, WHITE, M.m);
	}

	void InitAnimation(int minRange, int maxRange, float animTimer)
	{
		animMin = minRange;
		animMax = maxRange;
		(*this).animTimer = animTimer;
		startTimer = (*this).animTimer;
	}

	void UpdateAnim(float dt)
	{
		animTimer -= dt;

		if (animTimer <= 0)
		{
			idx++;
			animTimer = startTimer;
		}

		if (idx > animMax)
			idx = animMin + 1;
	}
};