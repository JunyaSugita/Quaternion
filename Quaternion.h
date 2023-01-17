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
	void Identity();
	void Conjugation();
	float norm();
	void unit();
	void Inverse();

	Quaternion Multiply(Quaternion q1, Quaternion q2);
};

