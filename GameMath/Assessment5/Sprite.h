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

	void DrawAnim(const Transform &t, bool grounded, float dt, const mat3 &cam = mat3::Identity())
	{
		mat3 M = cam * t.GetGlobalTransform() * Translate(offset) * Scale(dim);
		if (sfw::getKey('D') && grounded)
		{
			if (animMin != 0 && animMax != 3)
				InitAnimation(0, 3, 0.1f);
			UpdateAnim(dt);
		}
		if (sfw::getKey('A') && grounded)
		{
			if (animMin != 21 && animMax != 24)
			{
				InitAnimation(21, 24, 0.1f);
				idx = 21;
			}
			UpdateAnim(dt);
		}
		if (sfw::getKey(' ') && !grounded)
		{
			if (animMin == 0 && animMax == 3)
			{
				InitAnimation(5, 5, 0);
				idx = 5;
			}
			else if (animMin == 21 && animMax == 24)
			{
				InitAnimation(26, 26, 0);
				idx = 26;
			}
		}
		if (!sfw::getKey('A') && !sfw::getKey('D') /*&& !sfw::getKey(' ')*/)
		{
			if (idx >= 0 && idx < 4)
				idx = 0;
			else if (idx >= 21 && idx < 25)
				idx = 21;
		}
		
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