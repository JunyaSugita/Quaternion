#pragma once

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
	Quaternion Identity();
	Quaternion Conjugation(Quaternion q);
	float norm()const;
	Quaternion& unit();
	Quaternion Inverse(Quaternion q);
	Quaternion Multiply(Quaternion q1, Quaternion q2);

	Quaternion& operator/=(Quaternion q);
	Quaternion& operator/(float f);
};

