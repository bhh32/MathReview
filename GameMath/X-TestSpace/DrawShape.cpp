#include "DrawShape.h"
#include "Transform.h"
#include "sfwdraw.h"

void DrawCircle(const Circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void DrawAABB(const AABB &aabb)
{
	sfw::drawLine(aabb.maxCorner.x, aabb.maxCorner.y, aabb.maxCorner.x, aabb.minCorner.y, BLUE);
	sfw::drawLine(aabb.maxCorner.x, aabb.minCorner.y, aabb.minCorner.x, aabb.minCorner.y, BLUE);
	sfw::drawLine(aabb.minCorner.x, aabb.minCorner.y, aabb.minCorner.x, aabb.maxCorner.y, BLUE);
	sfw::drawLine(aabb.minCorner.x, aabb.maxCorner.y, aabb.maxCorner.x, aabb.maxCorner.y, BLUE);
}
