#pragma once

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H
#define PI 3.14159265359

class Functions
{
public:
	// Walkthrough Function
	float Square(float x);
	float SquareSub(float x, float y);

	// Closed Functions
	int Double(int x);
	int Cube(int x);
	float DegToRad(float deg);
	float RadToDeg(float rad);

	// Open Functions
	float BasicQuadratic(float x);
	void Quadratic(float a, float b, float c);
	float Lerp(float start, float end, float alpha);
	float Distance(float x1, float y1, float x2, float y2);

	// Challenge Functions
	float PlanePointDist(float x1, float y1, float x2, float y2);
};
#endif MATHFUNCTIONS_H