#include "MathFunctions.h"
#include <iostream>
#include <math.h>

float Functions::Square(float x)
{
	return x * x;
}

float Functions::SquareSub(float x, float y) 
{
	return (x - y) * (x - y);
}

int Functions::Double(int x)
{
	return x * 2;
}

int Functions::Cube(int x)
{
	return x * x * x;
}

float Functions::DegToRad(float deg)
{
	float rad = deg * (PI / 180);
	return rad;
}

float Functions::RadToDeg(float rad)
{
	float deg = rad * (180 / PI);
	return deg;
}

float Functions::BasicQuadratic(float x)
{
	return 0.0f;
}

void Functions::Quadratic(float a, float b, float c)
{
	float functionPos = ((-b + sqrtf((Square(b)) - (4 * a * c))) / (2 * a));
	float functionNeg = ((-b - sqrtf((Square(b)) - (4 * a * c))) / (2 * a));

	std::cout << "The pos root is: " << functionPos << std::endl;
	std::cout << "The neg root is: " << functionNeg << std::endl;
}

float Functions::Lerp(float start, float end, float alpha)
{
	float lerp = start + alpha * (end - start);
	return lerp;
}

float Functions::Distance(float x1, float y1, float x2, float y2)
{
	return sqrtf(SquareSub(x2, x1) + (SquareSub(y2, y1)));
}

float Functions::PlanePointDist(float x1, float y1, float x2, float y2)
{
	return 0.0f;
}
