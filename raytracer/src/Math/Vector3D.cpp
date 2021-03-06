//
// Created by ninig on 4/11/2020.
//

#include <cmath>

#include "Vector3D.h"
#include "Normal.h"
#include "Point3D.h"


Vector3D::Vector3D(): x(0.0), y(0.0), z(0.0) {}

Vector3D::Vector3D(double a): x(a), y(a), z(a) {}

Vector3D::Vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

Vector3D::Vector3D(const Vector3D& v): x(v.x), y(v.y), z(v.z) {}

Vector3D::Vector3D(const Normal& n): x(n.x), y(n.y), z(n.z) {}

Vector3D::Vector3D(const Point3D& p): x(p.x), y(p.y), z(p.z) {}

Vector3D::~Vector3D () = default;

Vector3D&
Vector3D::operator= (const Vector3D& rhs) {
    if (this == &rhs)
        return *this;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Vector3D&
Vector3D::operator= (const Normal& rhs) {
    if (this == (Vector3D*)&rhs)
        return *this;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Vector3D&
Vector3D::operator= (const Point3D& rhs) {
    if (this == (Vector3D*)&rhs)
        return *this;
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Vector3D
Vector3D::operator- () const {
    return Vector3D(-x, -y, -z);
}

Vector3D
Vector3D::operator* (const double a) const {
    return Vector3D(x*a, y*a, z*a);
}

Vector3D
Vector3D::operator/ (const double a) const {
    return Vector3D(x/a, y/a, z/a);
}

Vector3D
Vector3D::operator+ (const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D&
Vector3D::operator+= (const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D
Vector3D::operator- (const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

double
Vector3D::operator* (const Vector3D& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3D
Vector3D::operator^ (const Vector3D& v) const {
    return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

double
Vector3D::length() const {
    return sqrt(len_squared());
}

double
Vector3D::len_squared() const {
    return x*x + y*y + z*z;
}

void
Vector3D::normalize() {
    double length = Vector3D::length();
    x /= length;
    y /= length;
    z /= length;
}

Vector3D&
Vector3D::hat() {
    normalize();
    return *this;
}