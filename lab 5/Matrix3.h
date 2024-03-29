#pragma once

#include <math.h>
#include "Vector3.h"

class Matrix3
{
public:

	float A11;
	float A12;
	float A13;
    float A21;
	float A22;
	float A23;
	float A31;
	float A32;
	float A33;

	//constructors
	Matrix3();

	Matrix3(Vector3 row1, Vector3 row2, Vector3 row3);

	Matrix3(float _A11, float _A12, float _A13,
		float _A21, float _A22, float _A23,
		float _A31, float _A32, float _A33);

	Vector3 operator *(Vector3 V1);

	static Matrix3 Transpose(Matrix3 M1);
	
	 Matrix3 operator +(Matrix3 M2);
	
	 Matrix3 operator -(Matrix3 M2);
	
	 Matrix3 operator *(float x);

	 Matrix3 operator *(Matrix3 M2);

	static float Determinant(Matrix3 M1);

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

	 std::string toString()const; //done

};