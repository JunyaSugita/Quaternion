#include "Vector3.h"
#include <cmath>	//sqrt

Vector3::Vector3()
	:x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

float Vector3::length() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector3& Vector3::normalize() {
	float len = length();
	if (len != 0) {
		return *this /= length();
	}
	return *this;
}

float Vector3::dot(const Vector3& v) const {
	return (x * v.x) + (y * v.y) + (z * v.z);
}

Vector3 Vector3::cross(const Vector3& v) const {
	return  Vector3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y - v.x));
}

Vector3 Vector3::operator+() const {
	return *this;
}

Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

//Vector3 �N���X�ɑ����Ȃ��֐��Q
//2�����Z�q
const Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3  temp(v1);
	return temp += v2;
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	Vector3 tenp(v1);
	return tenp -= v2;
}

const Vector3 operator*(const Vector3& v, float s) {
	Vector3 temp(v);
	return temp *= s;
}

const Vector3 operator*(float s, const Vector3& v) {
	return v * s;
}

const Vector3 operator/(const Vector3& v, float s) {
	Vector3 temp(v);
	return v / s;
}

Vector3 Normalize(Vector3 v)
{
	Vector3 ans;
	ans = v.normalize();

	return ans;
}

float Dot(Vector3 a, Vector3 b)
{
	float ans;

	ans = a.x * b.x + a.y * b.y + a.z * b.z;

	return ans;
}

Vector3 Cross(Vector3 a, Vector3 b)
{
	return { (a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y - b.x) };
}
