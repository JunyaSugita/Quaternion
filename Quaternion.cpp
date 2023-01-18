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

Quaternion Quaternion::Identity()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Quaternion Quaternion::Conjugation(Quaternion q)
{
	q.x *= -1;
	q.y *= -1;
	q.z *= -1;
	return q;
}

float Quaternion::norm()const
{
	return sqrt(w * w + x * x + y * y + z * z);
}

Quaternion& Quaternion::unit()
{
	float len = norm();
	if (len != 0) {
		return *this /= norm();
	}
	return *this;
}

Quaternion Quaternion::Inverse(Quaternion q)
{
	//norm() * norm() / Conjugation(q);
}

Quaternion Quaternion::Multiply(Quaternion q1, Quaternion q2)
{
	Quaternion ans;

	ans.x = q1.y * q2.z - q1.z * q2.y + q2.w * q1.x + q2.w * q1.x;
	ans.y = q1.z * q2.x - q1.x * q2.z + q2.w * q1.y + q2.w * q1.y;
	ans.z = q1.x * q2.y - q1.y * q2.x + q2.w * q1.z + q2.w * q1.z;
	ans.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;

	return ans;
}

Quaternion& Quaternion::operator/=(Quaternion q)
{
	return Quaternion();
}

Quaternion& Quaternion::operator/(float f)
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;

	return *this;
}


