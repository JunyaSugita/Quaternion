#pragma once
#include "Vector3.h"
#include "Matrix4.h"

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion& Identity();
	Quaternion& Conjugation(const Quaternion& q);
	float norm(const Quaternion& q);
	float& norm();
	Quaternion& Normalize(const Quaternion& q);
	Quaternion& Inverse(const Quaternion& q);
	Quaternion Multiply(Quaternion q1, Quaternion q2);

	Quaternion MakeAxisAngle(const Vector3& axis, float angle);
	Vector3 RotateVector(const Vector3& vector, const Quaternion& q);
	Matrix4 MakeRotateMatrix(const Quaternion& q);

	float Dot(const Quaternion q1, const Quaternion& q2);
	Quaternion Slerp(const Quaternion& q0, const Quaternion& q1,float t);

	Quaternion& operator+=(const Quaternion& q);
	Quaternion& operator*=(const Quaternion& q);
	Quaternion& operator*=(float f);
	Quaternion& operator/=(float s);
	Quaternion& operator/(float f);
};

const Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
const Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
const Quaternion operator*(const Quaternion& q, float f);
const Quaternion operator*(float f, const Quaternion& q);