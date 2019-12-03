#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x1, float y1)
{
	x = x1;
	y = y1;
}

float Vector2::Length()
{
	// A method to return the length of the vector
	return (float)sqrt(x * x + y * y);
}

float Vector2::LengthSquared()
{
	// A method to return the length squared of the vector
	return (x * x + y * y);
}

void Vector2::Normalise()
{ // A method to reduce the length of the vector to 1.0 
			// keeping the direction the same
	if (Length() > 0.0)
	{  // Check for divide by zero
		float magnit = Length();
		x /= magnit;
		y /= magnit;
	}
}

Vector2 Vector2::operator+(Vector2 V2)
{
	// An overloaded operator + to return the sum of 2 vectors
	return Vector2(x + V2.x, y + V2.y);
}

Vector2 Vector2::operator-(Vector2 V2)
{
	// An overloaded operator - to return the difference of 2 vectors
	return Vector2(x - V2.x, y - V2.y);
}

float Vector2::operator*(Vector2 V2)
{
	// An overloaded operator * to return the scalar product of 2 vectors
	return (x * V2.x + y * V2.y);
}

Vector2 Vector2::operator*(float k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector2(x * (float)k, y * (float)k);
}

Vector2 Vector2::operator*(int k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector2(x * k, y * k);
}

std::string Vector2::ToString()
{
	return std::string(" x: " + std::to_string(x) + " y: " + std::to_string(y));
}

Vector2 Vector2::operator-()
{
	// An overloaded operator - to return the negation of a single vector
	Vector2 V1 = Vector2();
	V1.x = -x;
	V1.y = -y;
	return V1;
}


