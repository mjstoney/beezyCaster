#include "Mat2.h"

Vec2 Mat2::operator*(const Vec2& v)
{
    double x = m00 * v.x + m01 * v.y;
    double y = m10 * v.x + m11 * v.y;
    return Vec2(x, y);
}
