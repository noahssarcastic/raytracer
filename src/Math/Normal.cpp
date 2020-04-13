//
// Created by ninig on 4/12/2020.
//

#include "Normal.h"
#include <math.h>

Normal::Normal(void): x(0.0), y(0.0), z(0.0) {}

Normal::Normal(double a): x(a), y(a), z(a) {}

Normal::Normal(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

Normal::Normal::Normal(const Normal& n): x(n.x), y(n.y), z(n.z) {}

Normal::Normal(const Vector3D& v): x(v.x), y(v.y), z(v.z) {}

Normal::~Normal(void) {}

Normal&
Normal::operator= (const Normal& rhs) {
    if (this == &rhs)
        return *this;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Normal&
Normal::operator= (const Vector3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Normal&
Normal::operator= (const Point3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Normal
Normal::operator- (void) const {
    return Normal(-x, -y, -z);
}

Normal
Normal::operator+ (const Normal& n) const {
    return Normal(x + n.x, y + n.y, z + n.z);
}

Normal&
Normal::operator+= (const Normal& n) {
    x += n.x;
    y += n.y;
    z += n.z;
    return *this;
}

double
Normal::operator* (const Vector3D& v) const {
    return Normal(x * v.x, y * v.y, z * v.z);
}

Normal
Normal::operator* (const double a) const {
    return Normal(x * a, y * a, z * a);
}

void
Normal::normalize(void) {
    double length = sqrt(x*x + y*y + z*z);
    x /= length;
    y /= length;
    z /= length;
}