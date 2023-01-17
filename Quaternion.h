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
};

