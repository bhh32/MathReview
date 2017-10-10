#include "MathFunctions.h"
#include <iostream>
#include <cmath>

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
	return Square(x) + (2 * x) - 7;
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

float Functions::PlanePointDist(float pointVectorX, float pointVectorY, float pointVectorZ, float planeA, float planeB, float planeC, float planeD)
{
	/** To get the distance, the following formula is used distance = |(planeA * X) + (planeB * Y) + (planeC * Z) + planeD| / sqrt(planeA^2 + planeB^2 + planeC^2) **/
	float distance = (abs((planeA * pointVectorX) + (planeB + pointVectorY) + (planeC * pointVectorZ) + (planeD))) / (sqrtf(Square(planeA) + Square(planeB) + Square(planeC)));

	return distance;
}

void Functions::Quadratic(float a, float b, float c)
{
	float functionPos; // Used for the + root
	float functionNeg; // Used for the - root
	float realNum; // Used for if the determinate is negative
	float imaginaryNum; // Used for if the determinate is negative
	float determinate = (Square(b) - 4 * a * c); // Calculate the determinate

	// Checks the determinate
	if (determinate > 0)
	{
		// ... if it's greater than 0, Calculate normally
		functionPos = ((-b + sqrtf(determinate) / (2 * a)));
		functionNeg = ((-b - sqrtf(determinate) / (2 * a)));
	}
	else if (determinate == 0)
	{
		// ... if it's zero, both roots are equal to -b/2a
		functionPos = functionNeg = (float)(-b / (2 * a));		
	}
	else
	{
		// ... if it's negative, the roots are equaal to -b/2a +- imaginaryNum * sqrt(b) - 4ac
		realNum = (-b / (2 * a));
		imaginaryNum = sqrtf(-determinate) / (2 * a);
		functionPos = (realNum + (imaginaryNum * sqrt(-(Square(b) - 4 * a * c))));
		functionNeg = (realNum - (imaginaryNum * sqrt(-(Square(b) - 4 * a * c))));
	}

	std::cout << "The + root is: " << functionPos << std::endl;
	std::cout << "The - root is: " << functionNeg << std::endl;
}
