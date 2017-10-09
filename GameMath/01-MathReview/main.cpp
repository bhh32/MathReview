#include <iostream>
#include "MathFunctions.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	float userInput;
	float userInput2;
	float userInput3;
	float userInput4;
	Functions math;

	/*cout << "Enter a number to square: ";
	cin >> userInput;
	cout << math.Square(userInput) << endl;
	cout << endl;

	cout << "Enter a number to double: ";
	cin >> userInput;
	cout << math.Double(userInput) << endl;
	cout << endl;

	cout << "Enter a number to cube: ";
	cin >> userInput;
	cout << math.Cube(userInput) << endl;
	cout << endl;

	cout << "Enter a degree to convert to radians: ";
	cin >> userInput;
	cout << math.DegToRad(userInput) << endl;
	cout << endl;

	cout << "Enter a radian to convert to degrees: ";
	cin >> userInput;
	cout << math.RadToDeg(userInput) << endl;
	cout << endl;*/

	cout << "Enter 3 numbers for the quadradic equation: ";
	cin >> userInput;
	cin >> userInput2;
	cin >> userInput3;
	math.Quadratic(userInput, userInput2, userInput3);
	cout << endl;

	/*cout << "Enter two numbers for a range and a number between 0 and 1 for the alpha: ";
	cin >> userInput;
	cin >> userInput2;
	cin >> userInput3;
	cout << math.Lerp(userInput, userInput2, userInput3) << endl;
	cout << endl;

	cout << "Enter two points (x, y) to get the distance between: ";
	cin >> userInput;
	cin >> userInput2;
	cin >> userInput3;
	cin >> userInput4;
	cout << math.Distance(userInput, userInput2, userInput3, userInput4) << endl;
	cout << endl;*/

	system("pause");
	return 0;
}