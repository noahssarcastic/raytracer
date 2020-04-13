//
// Created by ninig on 4/11/2020.
//

#include <cmath>

#include "Point3D.h"


Point3D::Point3D(): x(0), y(0), z(0) {}

Point3D::Point3D(const double a): x(a), y(a), z(a)  {}

Point3D::Point3D(const double a, const double b, const double c): x(a), y(b), z(c)  {}

Point3D::Point3D(const Point3D& p): x(p.x), y(p.y), z(p.z) {}

Point3D::~Point3D() = default;

Point3D&
Point3D::operator= (const Point3D& rhs) {
    if (this == &rhs)
        return *this;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Point3D
Point3D::operator- () const {
    return Point3D(-x, -y, -z);
}

Vector3D
Point3D::operator- (const Point3D& p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D
Point3D::operator+ (const Vector3D& v) const {
    return Point3D(x + v.x, y + v.y, z + v.z);
}

Point3D
Point3D::operator- (const Vector3D& v) const {
    return Point3D(x - v.x, y - v.y, z - v.z);
}

Point3D
Point3D::operator* (const double a) const {
    return Point3D(x * a, y * a, z * a);
}

double
Point3D::d_squared(const Point3D& p) const {
    return pow(x - p.x, 2) + pow(y - p.y, 2) +	pow(z - p.z, 2);
}

double
Point3D::distance(const Point3D& p) const {
    return sqrt(this->d_squared(p));
}