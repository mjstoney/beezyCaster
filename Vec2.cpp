#include "Vec2.h"

Vec2 Vec2::operator+(const Vec2& rhs)
{
    return Vec2(x + rhs.x, y + rhs.x);
}

Vec2 Vec2::operator-(const Vec2& rhs)
{
    return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator*(const double& rhs)
{
    return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator/(const double& rhs)
{
    return Vec2(x / rhs, y / rhs);
}

double Vec2::dot(const Vec2& rhs)
{
    return x * rhs.x + y * rhs.y;
}

double Vec2::cross(const Vec2& rhs)
{
    return x * rhs.y - y * rhs.x;
}

double Vec2::magnitudeSq()
{
    return x * x + y * y;
}

double Vec2::magnitude()
{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::normalized()
{
    double m = magnitude();
    return Vec2(x / m, y / m);
}
