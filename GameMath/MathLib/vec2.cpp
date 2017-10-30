#include "vec2.h"
#include <cmath>
#include "mathutils.h"

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 &operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	// this isn't quite right, but game engines tend
	// to do something fairly close to this process
	//
	// floating-point math is weird! check this out!
	// http://floating-point-gui.de/errors/comparison/

	if (abs(lhs.x - rhs.x) < EPSILON &&
		abs(lhs.y - rhs.y) < EPSILON)
		return true;
	
	return false;
}

vec2 operator*(const vec2 &lhs, float rhs) 
{
	return{ lhs.x * rhs, lhs.y * rhs};
}

vec2 operator*(float lhs, const vec2 &rhs) 
{
	return{ lhs * rhs.x, lhs * rhs.y };
}

vec2 operator*=(vec2 &lhs, float &rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec2 operator/(const vec2 &lhs, const float &rhs) 
{
	return { (lhs.x / rhs), (lhs.y / rhs) };
}

vec2 operator/=(vec2 &lhs, const float & rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

vec2 operator-(vec2 & rhs) 
{
	return{ -rhs.x, -rhs.y };
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	if (abs(lhs.x - rhs.x) > EPSILON &&
		abs(lhs.y - rhs.y) > EPSILON)
		return true;

	return false;
}

bool operator<(const vec2 & lhs, const vec2 & rhs)
{
	if (lhs.x < rhs.x && lhs.y < rhs.y)
		return true;

	return false;
}

bool operator>(const vec2 &lhs, const vec2 &rhs)
{
	if (lhs.x > rhs.x && lhs.y > rhs.y)
		return true;

	return false;
}

bool operator<=(const vec2 &lhs, const vec2 &rhs)
{
	if (lhs.x <= rhs.x && lhs.y <= rhs.y)
		return true;

	return false;
}

bool operator>=(const vec2 &lhs, const vec2 &rhs)
{
	if (lhs.x >= rhs.x && lhs.y >= rhs.y)
		return true;

	return false;
}

float &vec2::operator[](int index)
{
	return v[index];
}

const float vec2::operator[](const int index) const
{
	return v[index];
}

float Magnitude(const vec2 vec)
{
	float length = abs(sqrt((vec.x * vec.x) + (vec.y * vec.y)));

	return length;
}

vec2 Normal(const vec2 &v)
{
	vec2 temp = v;

	float len = Magnitude(v);

	temp /= len;
	return temp;
}

vec2 &Normalize(vec2 &v)
{
	 v = Normal(v);
	
	return v;
}

float DotProduct(const vec2 &lhs, const vec2 &rhs)
{
	return{ (lhs.x * rhs.x) + (lhs.y * rhs.y) };
}

float Distance(const vec2 & lhs, const vec2 & rhs)
{
	return sqrt(((rhs.x - lhs.x) * (rhs.x - lhs.x)) + ((rhs.y - lhs.y) * (rhs.y - lhs.y)));
}

vec2 Perpendicular(const vec2 & vec)
{
	vec2 temp;
	temp.x = vec.y;
	temp.y = -vec.x;

	return temp;

}

vec2 Lerp(const vec2 &start, const vec2 &end, float time)
{
	return (start + time * (end - start));
}

vec2 Min(const vec2 & x, const vec2 & y)
{
	vec2 temp;

	if (x.x < y.x)
		temp.x = x.x;
	else if (x.x == y.x)
		temp.x = x.x;
	else
		temp.x = y.x;

	if (x.y < y.y)
		temp.y = x.y;
	else if (x.y == y.y)
		temp.y = x.y;
	else
		temp.y = y.y;

	return temp;
}

vec2 Max(const vec2 & x, const vec2 & y)
{
	vec2 temp;

	if (x.x > y.x)
		temp.x = x.x;
	else if (x.x == y.x)
		temp.x = x.x;
	else
		temp.x = y.x;

	if (x.y > y.y)
		temp.y = x.y;
	else if (x.y == y.y)
		temp.y = x.y;
	else
		temp.y = y.y;

	return temp;
}
