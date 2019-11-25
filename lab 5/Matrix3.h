#pragma once

#include <math.h>
#include "Vector3.h"

class Matrix3
{
public:

	double A11;
	double A12;
	double A13;
    double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;

	//constructors
	Matrix3();

	Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);

	Matrix3(double _A11, double _A12, double _A13,
		double _A21, double _A22, double _A23,
		double _A31, double _A32, double _A33);

	static Vector3 operator *(Matrix3 M1, Vector3 V1);

	static Vector3 operator *(Vector3 V1, Matrix3 M1);

	static Matrix3 Transpose(Matrix3 M1);
	
	static Matrix3 operator +(Matrix3 M1, Matrix3 M2);
	
	static Matrix3 operator -(Matrix3 M1, Matrix3 M2);
	
	static Matrix3 operator *(double x, Matrix3 M1);

	static Matrix3 operator *(Matrix3 M1, Matrix3 M2);


	
};