#ifndef VEC2_H
#define VEC2_H

#include <cmath>

class Vec2
{
public:
	double x, y;
	Vec2() : x(0), y(0) {}
	Vec2(double x, double y) : x(x), y(y) {}
	Vec2(const Vec2 &rhs) : x(rhs.x), y(rhs.y) {}

	Vec2 operator+(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs);
	Vec2 operator*(const double& rhs);
	Vec2 operator/(const double& rhs);
	double dot(const Vec2& rhs);
	double cross(const Vec2& rhs);
	double magnitudeSq();
	double magnitude();
	Vec2 normalized();
};

#endif // !VEC2_H
