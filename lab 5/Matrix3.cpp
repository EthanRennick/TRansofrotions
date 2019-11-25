#include "Matrix3.h"

Matrix3::Matrix3()
{
	 A11 = 0.0;
	 A12 = 0.0;
	 A13 = 0.0;
	 A21 = 0.0;
	 A22 = 0.0;
	 A23 = 0.0;
	 A31 = 0.0;
	 A32 = 0.0;
	 A33 = 0.0;
}

Matrix3::Matrix3(Vector3 row1, Vector3 row2, Vector3 row3)
{
	A11 = row1.x;
	A12 = row1.y;
	A13 = row1.z;
	A21 = row2.x;
	A22 = row2.y;
	A23 = row2.z;
	A31 = row3.x;
	A32 = row3.y;
	A33 = row3.z;
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21, double _A22, double _A23, double _A31, double _A32, double _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Vector3 Matrix3::operator*(Matrix3 M1, Vector3 V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return Vector3(M1.A11 * V1.x + M1.A12 * V1.y + M1.A13 * V1.z,
		M1.A21 * V1.z + M1.A22 * V1.y + M1.A23 * V1.z,
		M1.A31 * V1.z + M1.A32 * V1.y + M1.A33 * V1.z);
}

Vector3 Matrix3::operator*(Vector3 V1, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return  Vector3(M1.A11 * V1.x + M1.A21 * V1.y + M1.A31 * V1.z,
					M1.A12 * V1.x + M1.A22 * V1.y + M1.A32 * V1.z,
					M1.A13 * V1.x + M1.A23 * V1.y + M1.A33 * V1.z);
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{// a method to transpose a given matrix
	return Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

Matrix3 Matrix3::operator+(Matrix3 M1, Matrix3 M2)
{// An overloaded operator + to return the  sum of two matrix 
	return Matrix3(M1.A11 + M2.A11, M1.A12 + M2.A12, M1.A13 + M2.A13,
		M1.A21 + M2.A21, M1.A22 + M2.A22, M1.A23 + M2.A23,
		M1.A31 + M2.A31, M1.A32 + M2.A32, M1.A33 + M2.A33);
}

Matrix3 Matrix3::operator-(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  difference of two matrix
	return Matrix3(M1.A11 - M2.A11, M1.A12 - M2.A12, M1.A13 - M2.A13,
		M1.A21 - M2.A21, M1.A22 - M2.A22, M1.A23 - M2.A23,
		M1.A31 - M2.A31, M1.A32 - M2.A32, M1.A33 - M2.A33);
}

Matrix3 Matrix3::operator*(double x, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3 answer = Matrix3();
	answer.A11 = M1.A11 * x;
	answer.A12 = M1.A12 * x;
	answer.A13 = M1.A13 * x;

	answer.A21 = M1.A21 * x;
	answer.A22 = M1.A22 * x;
	answer.A23 = M1.A23 * x;

	answer.A31 = M1.A31 * x;
	answer.A32 = M1.A32 * x;
	answer.A33 = M1.A33 * x;

	return answer;
}

Matrix3 Matrix3::operator*(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  product of two matrix
	Matrix3 resultingMatrix; //create a matrix

	//pete's formula
	resultingMatrix = { M1.A11 * M2.A11 + M1.A12 * M2.A21 + M1.A13 * M2.A31, M1.A11 * M2.A12 + M1.A12 * M2.A22 + M1.A13 * M2.A32, M1.A11 * M2.A13 + M1.A12 * M2.A23 + M1.A13 * M2.A33, //multiply the corresponding components
		M1.A21 * M2.A11 + M1.A22 * M2.A21 + M1.A23 * M1.A31, 	M1.A21 * M2.A12 + M1.A22 * M2.A22 + M1.A23 * M2.A32, 	M1.A21 * M2.A13 + M1.A22 * M2.A23 + M1.A23 * M2.A33,
		M1.A31 * M2.A11 + M1.A32 * M2.A21 + M2.A33 * M2.A31,	 M1.A31 * M2.A12 + M1.A32 * M2.A22 + M1.A33 * M2.A32, M1.A31 * M2.A13 + M1.A32 * M2.A23 + M1.A33 * M2.A33 };

	return resultingMatrix; //return the answer
}