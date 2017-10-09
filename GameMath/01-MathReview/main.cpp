#include <iostream>
#include "MathFunctions.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Functions math;

	cout << "The number 1 Doubled is: " << math.Double(1.0f) << endl;
	cout << "The number 2 Doubled is: " << math.Double(2.0f) << endl;
	cout << "The number 3 Doubled is: " << math.Double(3.0f) << endl;
	cout << endl;

	cout << "The number 1 Cubed is: " << math.Cube(1.0f) << endl;
	cout << "The number 2 Cubed is: " << math.Cube(2.0f) << endl;
	cout << "The number 3 Cubed is: " << math.Cube(3.0f) << endl;
	cout << endl;

	cout << "180 deg converted to rads is: " << math.DegToRad(180.f) << endl;
	cout << "270 deg converted to rads is: " << math.DegToRad(270.f) << endl;
	cout << "360 deg converted to rads is: " << math.DegToRad(360.f) << endl;
	cout << endl;

	cout << "3.14159 rads converted to deg is: " << math.RadToDeg(3.14159) << endl;
	cout << "4.712389 rads converted to deg is: " << math.RadToDeg(4.712389) << endl;
	cout << "6.28319 rads converted to deg is: " << math.RadToDeg(6.28319) << endl;
	cout << endl;

	cout << "The y value for 0 is: " << math.BasicQuadratic(0) << endl;
	cout << "The y value for 5 is: " << math.BasicQuadratic(5) << endl;
	cout << "The y value for 1 is: " << math.BasicQuadratic(1) << endl;
	cout << endl;

	cout << "Lerp in range (0, 10) with offset of 0.0 is: " << math.Lerp(0, 10, 0.f) << endl;
	cout << "Lerp in range (0, 10) with offset of 1.0 is: " << math.Lerp(0, 10, 1.f) << endl;
	cout << "Lerp in range (0, 10) with offset of 0.5 is: " << math.Lerp(0, 10, 0.5f) << endl;
	cout << "Lerp in range (5, 10) with offset of 0.75 is: " << math.Lerp(5, 10, 0.75f) << endl;
	cout << endl;

	cout << "The distance between P1 (0, 0) and P2 (0, 2) is: " << math.Distance(0, 0, 0, 2) << endl;
	cout << "The distance between P1 (2, 0) and P2 (0, 0) is: " << math.Distance(2, 0, 0, 0) << endl;
	cout << "The distance between P1 (5, 5) and P2 (7, 7) is: " << math.Distance(5, 5, 7, 7) << endl;
	cout << endl;
	
	math.Quadratic(3, 7, 15);
	cout << endl;
	math.Quadratic(3, 2, 9);
	cout << endl;
	math.Quadratic(-3, 4, 12);
	cout << endl;

	system("pause");
	return 0;
}