#pragma once

#include <math.h>
#include <string>
#include <iostream>

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x1, float y1);

	float Length();

	float LengthSquared();

	void Normalise();

	Vector2 operator +(Vector2 V2);

	Vector2 operator -(Vector2 V2);

	Vector2 operator -();

	float operator *(Vector2 V2);

	Vector2 operator *(float k);

	Vector2 operator *(int k);

	std::string ToString();
};