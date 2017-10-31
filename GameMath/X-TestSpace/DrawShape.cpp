#include "DrawShape.h"
#include "sfwdraw.h"

void DrawCircle(const Circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void DrawAABB(const AABB &aabb)
{
	sfw::drawLine(aabb.max.x, aabb.max.y, aabb.max.x, aabb.min.y, BLUE);
	sfw::drawLine(aabb.max.x, aabb.min.y, aabb.min.x, aabb.min.y, BLUE);
	sfw::drawLine(aabb.min.x, aabb.min.y, aabb.min.x, aabb.max.y, BLUE);
	sfw::drawLine(aabb.min.x, aabb.max.y, aabb.max.x, aabb.max.y, BLUE);
}
