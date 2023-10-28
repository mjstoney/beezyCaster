#include "Vec2.h"
#ifndef MAT2_H
#define MAT2_H

class Mat2
{
public:
	union {
		struct {
			double m00, m01, m10, m11;
		};
		double values[4];
	};
	Mat2() {
		values[0] = m00 = 1;
		values[1] = m01 = 0;
		values[2] = m10 = 0;
		values[3] = m11 = 1;
	}

	Mat2(double a, double b, double c, double d) {
		values[0] = m00 = a;
		values[1] = m01 = b;
		values[2] = m10 = c;
		values[3] = m11 = d;
	}

	double* operator[](const int i);
	Vec2 operator*(const Vec2& v);


};

#endif // !MAT2_H
