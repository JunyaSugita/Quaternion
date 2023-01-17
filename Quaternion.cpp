#include "Quaternion.h"
#include "Math.h"

Quaternion::Quaternion()
	:x(0), y(0), z(0), w(0)
{
}

Quaternion::Quaternion(float x, float y, float z, float w)
	: x(x), y(y), z(z), w(w)
{
}

void Quaternion::Identity()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

void Quaternion::Conjugation()
{
	x *= -1;
	y *= -1;
	z *= -1;
}

float Quaternion::norm()
{
	float ans;
	ans = sqrt(w * w + x * x + y * y + z * z);

	return ans;
}

void Quaternion::unit()
{
	float norm;
	norm = sqrt(w * w + x * x + y * y + z * z);

	w /= norm;
	x /= norm;
	y /= norm;
	z /= norm;
}

void Quaternion::Inverse()
{

}

Quaternion Quaternion::Multiply(Quaternion q1, Quaternion q2)
{
	Quaternion ans;

	ans.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	ans.x = q1.y * q2.z - q1.z * q2.y + q2.w * q1.x + q2.w * q1.x;
	ans.y = q1.z * q2.x - q1.x * q2.z + q2.w * q1.y + q2.w * q1.y;
	ans.z = q1.x * q2.y - q1.y * q2.x + q2.w * q1.z + q2.w * q1.z;

	return ans;
}


