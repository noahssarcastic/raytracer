//
// Created by ninig on 4/12/2020.
//

#include "Plane.h"


const double Plane::kEpsilon = 0.001;

Plane::Plane(void): GeometricObject(), a(0.0), n(0, 1, 0) {}

Plane::Plane(const Point3D p, const Normal& _n): GeometricObject(), a(p), n(_n) {}

Plane::Plane(const Plane& plane): GeometricObject(), a(plane.a), n(plane.n) {}

Plane::~Plane(void) {}

Plane*
Plane::clone(void) const {
    return new Plane(*this);
}

Plane&
Plane::operator= (const Plane& rhs) {
    if (this == &rhs)
        return *this;
    GeometricObject::operator=(rhs);
    a = rhs.a;
    n = rhs.n;
    return *this;
}

bool
Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    float t = (a - ray.o) * n / (ray.d * n);
    if (t > kEpsilon) {
        tmin = t;
        sr.normal = n;
        sr.hit_point = ray.o + ray.d * t;
        return true;
    }
    return false;
}