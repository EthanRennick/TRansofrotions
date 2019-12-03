#pragma once
#include <iostream>
#include <string>

class Quaternion
{
private:

	double x, y, z, w;

public:

	Quaternion()
	{
		w = 0; x = 0; y = 0; z = 0;
	}

	Quaternion(double _w, double _x, double _y, double _z)
	{
		w = _w; x = _x; y = _y; z = _z;
	}

	Quaternion(double _w, Vector3 v)
	{
		w = _w; x = v.x; y = v.y; z = v.z;
	}

	std::string ToString()
	{
		return std::string("( w: " + std::to_string(w) + ", x:" + std::to_string(x) + ", y ," + std::to_string(y) + " z ," + std::to_string(z) + ")");
	}

	double Modulus()
	{ 
		return sqrt(w * w + x * x + y * y + z * z);
	}

    Quaternion Normalise()
	{
		double m = w * w + x * x + y * y + z * z;
		if (m > 0.001)
		{
			m = sqrt(m);
			return Quaternion(w / m, x / m, y / m, z / m);
		}
		else
		{
			return Quaternion(1, 0, 0, 0);
		}
	}

    Quaternion Conjugate()
	{
		return Quaternion(w, -x, -y, -z);
	}

	void FromAxisAngle(Vector3 axis, double angleRadian)
	{
		double m = axis.Length();
		if (m > 0.0001)
		{
			double ca = cos(angleRadian / 2);
			double sa = sin(angleRadian / 2);
			x = axis.x / m * sa;
			y = axis.y / m * sa;
			z = axis.z / m * sa;
			w = ca;
		}
		else
		{
			w = 1; x = 0; y = 0; z = 0;
		}
	}

	 Quaternion Multiply(Quaternion _q)
	{
		double nw = _q.w * w - _q.x * x - _q.y * y - _q.z * z;
		double nx = _q.w * x + _q.x * w + _q.y * z - _q.z * y;
		double ny = _q.w * y + _q.y * w + _q.z * x - _q.x * z;
		double nz = _q.w * z + _q.z * w + _q.x * y - _q.y * x;
		return  Quaternion(nw, nx, ny, nz);
	}

	 Quaternion Copy()
	{
		return  Quaternion(x, y, z, w);
	}
	//                  -1
	// V'=q*V*q     ,

	 Vector3 Rotate(Vector3 pt, int _angle)
	{
		Quaternion axis, rotate;
		axis = Normalise();
		double angleRad = 3.14 / 180 * _angle;
		rotate = Quaternion(cos(angleRad / 2), sin(angleRad / 2) * axis.x, sin(angleRad / 2) * axis.y, sin(angleRad / 2) * axis.z);
		Quaternion conjugate = rotate.Conjugate();
		Quaternion qNode = Quaternion(0, pt.x, pt.y, pt.z);
		qNode = rotate * qNode * conjugate;
		return Vector3(qNode.x, qNode.y, qNode.z);
	}

	// Multiplying q1 with q2 is meaning of doing q2 firstly then q1
	Quaternion operator +(Quaternion q2)
	{
		return Quaternion(w + q2.w, x + q2.x, y + q2.y, z + q2.z);
	}
	Quaternion operator -()
	{
		return Quaternion(-w, -x, -y, -z);
	}
	Quaternion operator -(Quaternion q2)
    {
		return Quaternion(w - q2.w, x - q2.x, y - q2.y, z - q2.z);
	}

	Quaternion operator *(float s)
	{
		return Quaternion(w * s, x * s,y * s, z * s);
	}
	Quaternion operator *(int s)
	{
		return Quaternion(w * s, x * s, y * s, z * s);
	}

	Quaternion operator *(double s)
	{
		return  Quaternion(w * s, x * s, y * s, z * s);
	}
	Quaternion operator *(Quaternion q2)
	{
		double nw = w * q2.w - x * q2.x - y * q2.y - z * q2.z;
		double nx = w * q2.x + x * q2.w + y * q2.z - z * q2.y;
		double ny = w * q2.y + y * q2.w + z * q2.x - x * q2.z;
		double nz = w * q2.z + z * q2.w + x * q2.y - y * q2.x;
		return Quaternion(nw, nx, ny, nz);
	}
};

