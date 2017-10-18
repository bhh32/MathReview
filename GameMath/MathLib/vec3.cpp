#include "vec3.h"
#include <cmath>
#include "mathutils.h"

vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 &operator+=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec3 operator-(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.x - rhs.y };
}

vec3 operator-=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs)
{
	// this isn't quite right, but game engines tend
	// to do something fairly close to this process
	//
	// floating-point math is weird! check this out!
	// http://floating-point-gui.de/errors/comparison/

	if (abs(lhs.x - rhs.x) < EPSILON &&
		abs(lhs.y - rhs.y) < EPSILON &&
		abs(lhs.z - rhs.z) < EPSILON)
		return true;

	return false;
}

vec3 operator*(vec3 &lhs, const float &rhs)
{
	return{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(const float &lhs, vec3 &rhs)
{
	return{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
}

vec3 operator*=(vec3 &lhs, const float &rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

vec3 operator/(const vec3 &lhs, const float &rhs)
{
	return{ (lhs.x / rhs), (lhs.y / rhs), (lhs.z / rhs) };
}

vec3 operator/=(vec3 &lhs, const float &rhs)
{
	lhs = lhs / rhs;
	return lhs;
}

vec3 operator-(vec3 &rhs)
{
	return{ -rhs.x, -rhs.y, -rhs.z };
}

bool operator!=(const vec3 &lhs, const vec3 &rhs)
{
	if (abs(lhs.x - rhs.x) > EPSILON &&
		abs(lhs.y - rhs.y) > EPSILON &&
		abs(lhs.z - rhs.z) > EPSILON)
		return true;

	return false;
}

bool operator<(const vec3 &lhs, const vec3 &rhs)
{
	if (lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z)
		return true;

	return false;
}

bool operator>(const vec3 &lhs, const vec3 &rhs)
{
	if (lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z)
		return true;

	return false;
}

bool operator<=(const vec3 &lhs, const vec3 &rhs)
{
	if (lhs.x <= rhs.x && lhs.y <= rhs.y && lhs.z <= rhs.z)
		return true;

	return false;
}

bool operator>=(const vec3 &lhs, const vec3 &rhs)
{
	if (lhs.x >= rhs.x && lhs.y >= rhs.y, lhs.z >= rhs.z)
		return true;

	return false;
}

float DistanceVec3(const vec3 &lhs, const vec3 &rhs)
{
	return sqrt(((rhs.x - lhs.x) * (rhs.x - lhs.x)) + ((rhs.y - lhs.y) * (rhs.y - lhs.y)) + (rhs.z - lhs.z) * (rhs.z - lhs.z));
}

float DotProductVec3(const vec3 &lhs, const vec3 &rhs)
{
	return{ (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z)};
}

vec3 CrossProduct(const vec3 &a, const vec3 &b)
{
	float x = (a.y * b.z) - (b.y * a.z);
	float y = (a.z * b.x) - (b.z * a.x);
	float z = (a.x * b.y) - (b.x * a.y);

	return{ x, y, z };
}

vec3 LerpVec3(const vec3 &start, const vec3 &end, float time)
{
	return (start + time * (end - start));
}

vec3 MinVec3(const vec3 &x, const vec3 &y)
{
	vec3 temp = x;
	
	temp.x = fmin(x.x, y.x);
	temp.y = fmin(x.y, y.y);
	temp.z = fmin(x.z, y.z);

	return{ temp.x, temp.y, temp.z };
}

vec3 MaxVec3(const vec3 &x, const vec3 &y)
{
	vec3 temp = x;

	temp.x = fmax(x.x, y.x);
	temp.y = fmax(x.y, y.y);
	temp.z = fmax(x.z, y.z);

	return{ temp.x, temp.y, temp.z };
}

vec3 Clamp(vec3 &vector, const vec3 a_min, const vec3 a_max)
{
	vector = MinVec3(vector, a_max);
	vector = MaxVec3(vector, a_min);

	return { vector.x, vector.y, vector.z };
}

float &vec3::operator[](const int index)
{
	return v[index];
}

const float vec3::operator[](const int index) const
{
	return v[index];
}

float vec3::Magnitude()
{
	float length = abs(sqrtf((x * x) + (y * y) + (z * z)));

	return length;
}

vec3 vec3::Normal()
{
	vec3 temp = { x / Magnitude(), y / Magnitude(), z / Magnitude() };
	return temp;
}

vec3 &vec3::Normalize()
{
	(*this) = Normal();

	return *this;
}
