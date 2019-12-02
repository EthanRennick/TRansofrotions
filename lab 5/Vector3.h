#pragma once

#include <math.h>
#include <string>
#include <iostream>

class Vector3
{
public:
	double x;
	double y;
	double z;

	Vector3();
	Vector3(double x1, double y1, double z1);
	
	double Length();

	double LengthSquared();

	void Normalise();

	 Vector3 operator +(Vector3 V2);

	 Vector3 operator -(Vector3 V2);

	 Vector3 operator -();

	 double operator *(Vector3 V2);

	 Vector3 operator *(double k);

	 Vector3 operator *(float k);

	 Vector3 operator *(int k);

	 Vector3 operator ^(Vector3 V2);

	 std::string ToString();
};