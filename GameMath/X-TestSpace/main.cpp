#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "mathutils.h"

using std::cout;
using std::endl;

int main()
{

	cout << "Vector2 Tests" << endl;
	cout << endl;

	vec2 testA;
	testA.x = 7;
	testA.y = 1;
	
	vec2 testB;
	testB.x = 3;
	testB.y = 2;

	// Addition
	vec2 vecSum = testA + testB;
	cout << "(" << vecSum.x << ", " << vecSum.y << ")" << endl;

	vecSum += testB;
	cout << "(" << vecSum.x << ", " << vecSum.y << ")" << endl;

	// Subtraction
	vec2 vecDiff = testA - testB;
	cout << "(" << vecDiff.x << ", " << vecDiff.y << ")" << endl;

	vecDiff -= testA;
	cout << "(" << vecDiff.x << ", " << vecDiff.y << ")" << endl;

	// Scalar Multiplication
	vec2 scalarMult = 3.0f * testA;
	cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	scalarMult = testB * 3.0f;
	cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	scalarMult *= 5.f;
	cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	// Scalar Division
	vec2 scalarDiv = testA / 5.0f;
	cout << "(" << scalarDiv.x << ", " << scalarDiv.y << ")" << endl;

	scalarDiv /= 10.f;
	cout << "(" << scalarDiv.x << ", " << scalarDiv.y << ")" << endl;

	// Logical Operators
	bool check = scalarDiv == vecDiff ? true : false;

	if (check)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	check = scalarDiv != vecDiff ? true : false;

	if (check)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	testA.v[0] = 12.f;
	testA.v[1] = 3.f;

	// Subscript Operator
	for (int i = 0; i < 2; ++i)
	{
		cout << testA.v[i] << endl;
	}

	// Magnitude
	vec2 mag1 = { 0, 1 };
	vec2 mag2 = { 1, 1 };
	vec2 mag3 = { -2, 3 };

	cout << mag1.Magnitude() << endl;
	cout << mag2.Magnitude() << endl;
	cout << mag3.Magnitude() << endl;

	// Normal
	vec2 mag1Norm = mag1.Normal();
	vec2 mag2Norm = mag2.Normal();
	vec2 mag3Norm = mag3.Normal();
	cout << "(" << mag1Norm.x << ", " << mag1Norm.y << ")" << endl;
	cout << "(" << mag2Norm.x << ", " << mag2Norm.y << ")" << endl;
	cout << "(" << mag3Norm.x << ", " << mag3Norm.y << ")" << endl;

	// Normalize
	mag1.Normalize();
	mag2.Normalize();
	mag3.Normalize();
	cout << "(" << mag1.x << ", " << mag1.y << ")" << endl;
	cout << "(" << mag2.x << ", " << mag2.y << ")" << endl;
	cout << "(" << mag3.x << ", " << mag3.y << ")" << endl;

	// Dot Product
	cout << DotProduct({ 2, 3 }, { 7, 5 }) << endl;
	cout << DotProduct({1, 0}, {1, 1}) << endl;
	cout << DotProduct({4, 0}, {1, -3}) << endl;

	// Distance
	cout << Distance({ 4, 0 }, { 1, -3 }) << endl;
	cout << Distance({ 8, 2 }, { 1, 4 }) << endl;
	cout << Distance({ 5, 12 }, { 0, 0 }) << endl;

	// Perpendicular Vector
	cout << "(" << Perpendicular({ 4, 0 }).x << ", " << Perpendicular({ 4, 0 }).y << ")" << endl;
	cout << "(" << Perpendicular({ 8, 2 }).x << ", " << Perpendicular({ 8, 2 }).y << ")" << endl;
	cout << "(" << Perpendicular({ -5, -12 }).x << ", " << Perpendicular({ -5, -12 }).y << ")" << endl;

	// Lerp
	cout << "(" << Lerp({ 0, 0 }, { 0, 5 }, 0.5f).x << ", " << Lerp({ 0, 0 }, { 0, 5 }, 0.5f).y << ")" << endl;
	cout << "(" << Lerp({ 0, 0 }, { 1, 1 }, 0.0f).x << ", " << Lerp({ 0, 0 }, { 1, 1 }, 0.0f).y << ")" << endl;
	cout << "(" << Lerp({ 5, 12 }, { 7, 4 }, 1.0f).x << ", " << Lerp({ 5, 12 }, { 7, 4 }, 1.0f).y << ")" << endl;

	// Min
	cout << "(" << Min({ 4, 0 }, { 1, -3 }).x << ", " << Min({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	cout << "(" << Min({ 8, 2 }, { 1, 4 }).x << ", " << Min({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	cout << "(" << Min({ 5, 12 }, { 0, 0 }).x << ", " << Min({ 5, 12 }, { 0, 0 }).y << ")" << endl;

	// Max
	cout << "(" << Max({ 4, 0 }, { 1, -3 }).x << ", " << Max({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	cout << "(" << Max({ 8, 2 }, { 1, 4 }).x << ", " << Max({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	cout << "(" << Max({ 5, 12 }, { 0, 0 }).x << ", " << Max({ 5, 12 }, { 0, 0 }).y << ")" << endl;
	std::cout << std::endl;

	cout << "Vector3 Tests" << endl;
	vec3 testA2;
	testA2.x = 7;
	testA2.y = 1;
	testA2.z = 2;

	vec3 testB2;
	testB2.x = 3;
	testB2.y = 2;
	testB2.z = 12;

	// Addition
	cout << "Vec3 + Operator Test" << endl;
	vec3 vecSum2 = testA2 + testB2;
	cout << "(" << vecSum2.x << ", " << vecSum2.y << ", " << vecSum2.z << ")" << endl;
	cout << endl;

	cout << "Vec3 += Operator Test" << endl;
	vecSum2 += testB2;
	cout << "(" << vecSum2.x << ", " << vecSum2.y << ", " << vecSum2.z << ")" << endl;
	cout << endl;

	// Subtraction
	cout << "Vec3 - Operator Test" << endl;
	vec3 vecDiff2 = testA2 - testB2;
	cout << "(" << vecDiff2.x << ", " << vecDiff2.y << ", " << vecDiff2.z << ")" << endl;
	cout << endl;

	cout << "Vec3 -= Operator Test" << endl;
	vecDiff2 -= testA2;
	cout << "(" << vecDiff2.x << ", " << vecDiff2.y << ", " << vecDiff2.z << ")" << endl;
	cout << endl;

	// Scalar Multiplication
	cout << "Vec3 Scalar * vec3 Operator Test" << endl;
	vec3 scalarMult2 = 3.0f * testA2;
	cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;
	cout << endl;

	cout << "Vec3 vec3 * scalar Operator Test" << endl;
	scalarMult2 = testB2 * 3.0f;
	cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;

	scalarMult2 *= 5.f;
	cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;

	// Scalar Division
	vec3 scalarDiv2 = testA2 / 5.0f;
	cout << "(" << scalarDiv2.x << ", " << scalarDiv2.y << ", " << scalarDiv2.z << ")" << endl;

	scalarDiv2 /= 10.f;
	cout << "(" << scalarDiv2.x << ", " << scalarDiv2.y << ", " << scalarDiv2.z << ")" << endl;
	cout << endl;

	// Logical Operators
	cout << "Vec3 Logical Operators Test" << endl;
	bool check2 = scalarDiv2 == vecDiff2 ? true : false;

	if (check2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	check2 = scalarDiv2 != vecDiff2 ? true : false;

	if (check2)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	testA2.v[0] = 12.6f;
	testA2.v[1] = 3.12f;
	testA2.v[2] = 8.9f;
	cout << endl;

	// Subscript Operator
	cout << "Vec3 Subscript Operator Test" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << testA2.v[i] << endl;
	}
	cout << endl;
	// Magnitude
	cout << "Vec3 Magnitude Function Test" << endl;

	vec3 mag4 = { 0, 1, 4 };
	vec3 mag5 = { 1, 1, 1 };
	vec3 mag6 = { -2, 3, 0 };

	cout << mag4.Magnitude() << endl;
	cout << mag5.Magnitude() << endl;
	cout << mag6.Magnitude() << endl;
	cout << endl;

	// Normal
	cout << "Vec3 Normal Function Test" << endl;
	vec3 mag4Norm = mag4.Normal();
	vec3 mag5Norm = mag5.Normal();
	vec3 mag6Norm = mag6.Normal();
	cout << "(" << mag4Norm.x << ", " << mag4Norm.y << ")" << endl;
	cout << "(" << mag5Norm.x << ", " << mag5Norm.y << ")" << endl;
	cout << "(" << mag6Norm.x << ", " << mag6Norm.y << ")" << endl;
	cout << endl;

	// Normalize
	cout << "Vec3 Normalize Function Test\n";
	mag4.Normalize();
	mag5.Normalize();
	mag6.Normalize();
	cout << "(" << mag4.x << ", " << mag4.y << ")" << endl;
	cout << "(" << mag5.x << ", " << mag5.y << ")" << endl;
	cout << "(" << mag6.x << ", " << mag6.y << ")" << endl;
	cout << endl;

	// Dot Product
	cout << "Vec3 Dot Product Function Test" << endl;
	vec3 dotA = { 9, 2, 7 };
	vec3 dotB = { 4, 8, 10 };
	cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	dotA = { 7, 4, 6 };
	dotB = { 67, 13, 10 };
	cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	dotA = { 19, 8, 3 };
	dotB = { 7, 12, 0 };
	cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	cout << endl;
	// Cross Product
	cout << "Vec3 Cross Product Function Test" << endl;
	vec3 a = { 1, 2, 3 };
	vec3 b = { 4, 5, 6 };
	cout << "(" << CrossProduct(a, b).x << ", " << CrossProduct(a, b).y << ", " << CrossProduct(a, b).z << ")" << endl;
	a = { 1, 0, 1 };
	b = { 1, 1, 10 };
	cout << "(" << CrossProduct(a, b).x << ", " << CrossProduct(a, b).y << ", " << CrossProduct(a, b).z << ")" << endl;
	a = { 12, 4, 2 };
	b = { 3, 0, -3 };
	cout << "(" << CrossProduct(a, b).x << ", " << CrossProduct(a, b).y << ", " << CrossProduct(a, b).z << ")" << endl;
	cout << endl;

	// Distance
	cout << "Vec3 Distance Function Test" << endl;
	cout << "Dist Vec3: " << DistanceVec3({ 4, 0, 1 }, { 1, -3, 2 }) << endl;
	cout << "Dist Vec3: " << DistanceVec3({ 8, 2, 10 }, { 1, 4, 3 }) << endl;
	cout << "Dist Vec3: " << DistanceVec3({ 5, 12, -6 }, { 0, 0, 0 }) << endl;
	cout << endl;

	// Lerp
	cout << "Vec3 Lerp Function Test" << endl;
	vec3 lerpA = { 0, 0, 12 };
	vec3 lerpB = { 0, 5, 6 };
	float time = .5f;
	cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	lerpA = { 0, 0, 1 };
	lerpB = { 1, 1, 12 };
	time = .25f;
	cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	lerpA = { 5, 12, 8 };
	lerpB = { 7, 4, 13 };
	time = 1.f;
	cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	cout << endl;
	// Min
	cout << "Vec3 Min Function Test" << endl;
	cout << "(" << MinVec3({ 4, 0 }, { 1, -3 }).x << ", " << MinVec3({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	cout << "(" << MinVec3({ 8, 2 }, { 1, 4 }).x << ", " << MinVec3({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	cout << "(" << MinVec3({ 5, 12 }, { 0, 0 }).x << ", " << MinVec3({ 5, 12 }, { 0, 0 }).y << ")" << endl;

	// Max
	cout << "(" << MaxVec3({ 4, 0 }, { 1, -3 }).x << ", " << MaxVec3({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	cout << "(" << MaxVec3({ 8, 2 }, { 1, 4 }).x << ", " << MaxVec3({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	cout << "(" << MaxVec3({ 5, 12 }, { 0, 0 }).x << ", " << MaxVec3({ 5, 12 }, { 0, 0 }).y << ")" << endl;
	std::cout << std::endl;

	while (true) {};
	return 0;
}