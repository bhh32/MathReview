#include "Transform.h"
#include "sfwdraw.h"
Transform::Transform()
{
	position = vec2{ 0, 0 };
	demension = vec2{ 0,0 };
	angle = 0;
}

mat3 Transform::GetLocalTransform()
{
	return Translate(position) * Scale(demension) * Rotation(angle);
}

void DrawMatrix(const mat3 &t, float drawing_scale)
{
	// Base position in matrix
	vec2 pos = t[2].xy;

	vec2 rightEndPoint = pos + t[0].xy * drawing_scale;
	vec2 upEndPoint = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, rightEndPoint.x, rightEndPoint.y, RED);
	sfw::drawLine(pos.x, pos.y, upEndPoint.x, upEndPoint.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}
