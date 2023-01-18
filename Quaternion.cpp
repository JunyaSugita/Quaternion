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

Quaternion& Quaternion::Identity()
{
	return *this = { 0,0,0,1 };
}

Quaternion& Quaternion::Conjugation(const Quaternion& q)
{
	Quaternion temp(q);
	temp.x *= -1;
	temp.y *= -1;
	temp.z *= -1;
	return *this = temp;
}

float Quaternion::norm(const Quaternion& q)
{
	return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
}

float& Quaternion::norm()
{
	Quaternion q = *this;
	float temp = sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	return temp;
}

Quaternion& Quaternion::Normalize(const Quaternion& q)
{
	Quaternion qua = q;
	float len = norm(qua);
	if (len != 0) {
		return *this = qua / len;
	}
	return *this = qua;
}

Quaternion& Quaternion::Inverse(const Quaternion& q)
{
	Quaternion temp;
	temp = Conjugation(q) / (norm(q) * norm(q));

	return temp;
}

Quaternion Quaternion::Multiply(Quaternion q1, Quaternion q2)
{
	Quaternion temp;

	temp.x = q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
	temp.y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
	temp.z = q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
	temp.w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;

	return temp;
}

Quaternion Quaternion::MakeAxisAngle(const Vector3& axis, float angle)
{
	Quaternion q;
	Vector3 vec = axis;
	vec.normalize();
	q.w = cos(angle / 2);
	q.x = vec.x * sin(angle / 2);
	q.y = vec.y * sin(angle / 2);
	q.z = vec.z * sin(angle / 2);

	return q;
}

Vector3 Quaternion::RotateVector(const Vector3& vector, const Quaternion& q)
{
	Quaternion r = {vector.x,vector.y,vector.z,0 };

	r = q * r * Conjugation(q);

	return Vector3(r.x, r.y, r.z);
}

Matrix4 Quaternion::MakeRotateMatrix(const Quaternion& q)
{
	return Matrix4(
		q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z,2 * (q.x * q.y + q.w * q.z),2 * (q.x * q.z - q.w * q.y),0,
		2 * (q.x * q.y - q.w * q.z), q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z,2 * (q.y * q.z + q.w * q.x),0,
		2 * (q.x * q.z + q.w * q.y), 2 * (q.y * q.z - q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z,0,
		0,0,0,1
	);
}

Quaternion& Quaternion::operator*=(const Quaternion& q)
{
	Quaternion temp;
	Quaternion q1 = *this;

	temp.x = q1.x * q.w + q1.y * q.z - q1.z * q.y + q1.w * q.x;
	temp.y = -q1.x * q.z + q1.y * q.w + q1.z * q.x + q1.w * q.y;
	temp.z = q1.x * q.y - q1.y * q.x + q1.z * q.w + q1.w * q.z;
	temp.w = -q1.x * q.x - q1.y * q.y - q1.z * q.z + q1.w * q.w;

	return temp;
}

Quaternion& Quaternion::operator*=(float f)
{
	x *= f;
	y *= f;
	z *= f;
	w *= f;

	return *this;
}

Quaternion& Quaternion::operator/=(float s)
{

	return *this *= 1.0f / s;
}

Quaternion& Quaternion::operator/(float f)
{
	x /= f;
	y /= f;
	z /= f;
	w /= f;

	return *this;
}

const Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion temp(q1);
	return temp *= q2;
}

const Quaternion operator*(const Quaternion& q, float f)
{
	Quaternion temp(q);
	return temp *= f;
}
