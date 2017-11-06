#include "DrawShape.h"
#include "Transform.h"
#include "sfwdraw.h"

void DrawCircle(const Circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void DrawVecLine(const vec2 &a, const vec2 &b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void DrawAABB(const AABB &box, int color)
{
	vec2 topRight = box.position + box.extents;
	vec2 bottomLeft = box.position - box.extents;
	vec2 topLeft = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 bottomRight = { topRight.x, bottomLeft.y };

	DrawVecLine(topRight, topLeft, color);
	DrawVecLine(topLeft, bottomLeft, color);
	DrawVecLine(bottomLeft, bottomRight, color);
	DrawVecLine(bottomRight, topRight, color);
}