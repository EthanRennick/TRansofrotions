#include "Vector3.h"

Vector3::Vector3()
{
	
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	
}

Vector3::Vector3(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}

double Vector3::Length()
{
	// A method to return the length of the vector
	return (double)sqrt(x * x + y * y + z * z);

}

double Vector3::LengthSquared()
{
	// A method to return the length squared of the vector
	return (x * x + y * y + z * z);
}

void Vector3::Normalise()
{ // A method to reduce the length of the vector to 1.0 
			// keeping the direction the same
	if (Length() > 0.0)
	{  // Check for divide by zero
		double magnit = Length();
		x /= magnit;
		y /= magnit;
		z /= magnit;
	}
}

Vector3 Vector3::operator+( Vector3 V2)
{
	// An overloaded operator + to return the sum of 2 vectors
	return Vector3(x + V2.x, y + V2.y, z + V2.z);
}

Vector3 Vector3::operator-(Vector3 V2)
{
	// An overloaded operator - to return the difference of 2 vectors
	return Vector3(x - V2.x, y - V2.y, z - V2.z);
}

double Vector3::operator*(Vector3 V2)
{
	// An overloaded operator * to return the scalar product of 2 vectors
	return (x * V2.x + y * V2.y + z * V2.z);
}

Vector3 Vector3::operator*(double k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * (float)k, y * (float)k, z * (float)k);
}

Vector3 Vector3::operator*(float k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * k, y * k, z * k);
}

Vector3 Vector3::operator*(int k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * k, y * k, z * k);
}

Vector3 Vector3::operator^(Vector3 V2)
{
	// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3(y * V2.z - z * V2.y, z * V2.x - x * V2.z, x * V2.y - y * V2.x);
}

std::string Vector3::ToString()
{
	return std::string(" x: " + std::to_string(x) + " y: " + std::to_string(y) + " z: " + std::to_string(z));
}

Vector3 Vector3::operator-()
{
	// An overloaded operator - to return the negation of a single vector
	Vector3 V1 = Vector3();
	V1.x = -x;
	V1.y = -y;
	V1.z = -z;
	return V1;
}


