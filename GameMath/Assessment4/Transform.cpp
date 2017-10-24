#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(vec2 position, vec2 demension, float angle)
{
	this->position = position;
	
	this->demension = demension;
	this->angle = angle;
	e_parent = nullptr;
}

mat3 Transform::GetLocalTransform() const
{
	return Translate(position) * Scale(demension) * Rotation(angle);
}

mat3 Transform::GetGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->GetGlobalTransform() * GetLocalTransform();
	}
	else
	{
		return GetLocalTransform();
	}
}

void Transform::DrawMatrix(const mat3 &t, float drawing_scale)
{
	// Base position in matrix
	vec2 pos = t[2].xy;

	vec2 rightEndPoint = pos + t[0].xy * drawing_scale;
	vec2 upEndPoint = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, rightEndPoint.x, rightEndPoint.y, RED);
	sfw::drawLine(pos.x, pos.y, upEndPoint.x, upEndPoint.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}

void Transform::DrawTexture(unsigned sprite, const mat3 & t)
{
	                                       // float mat[9]
	sfw::drawTextureMatrix3(sprite, 0, WHITE, t.m);
}
