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

	Vector3 operator *(Vector3 V1);

	static Matrix3 Transpose(Matrix3 M1);
	
	 Matrix3 operator +(Matrix3 M2);
	
	 Matrix3 operator -(Matrix3 M2);
	
	 Matrix3 operator *(double x);

	 Matrix3 operator *(Matrix3 M2);

	static double Determinant(Matrix3 M1);

	Vector3 Row(int i);

	Vector3 Column(int i);

	static Matrix3 Inverse(Matrix3 M1);

	static Matrix3 Rotation(int _angle);

	static Matrix3 Translate(int dx, int dy);

	 Matrix3 Scale(int dx, int dy);

	 Matrix3 operator -();

	 Matrix3 RotationX(int _angle);

	 Matrix3 RotationY(int _angle);

	 Matrix3 RotationZ(int _angle);
	
	 Matrix3 Scale3D(int dx);
};