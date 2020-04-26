//
// Created by ninig on 4/11/2020.
//

#include <cmath>

#include <Vector3D.h>
#include "Sphere.h"
#include "Point3D.h"


const double Sphere::kEpsilon = 0.001;

Sphere::Sphere(): GeometricObject(), center(0.0), radius(1.0) {}

Sphere::Sphere(Point3D c, double r): GeometricObject(), center(c), radius(r) {}

Sphere::Sphere(const Sphere& sphere): GeometricObject(sphere), center(sphere.center), radius(sphere.radius) {}

Sphere::~Sphere() {}

Sphere*
Sphere::clone() const {
    return new Sphere(*this);
}

Sphere&
Sphere::operator= (const Sphere& rhs) {
    if (this == &rhs)
        return *this;
    GeometricObject::operator=(rhs);
    center = rhs.center;
    radius = rhs.radius;
    return *this;
}

void
Sphere::set_center(const Point3D& c) {
    center = c;
}

void
Sphere::set_center(const double x, const double y, const double z) {
    center.x = x;
    center.y = y;
    center.z = z;
}

void
Sphere::set_radius(const double r) {
    radius = r;
}

bool
Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double 		t;
    Vector3D	temp 	= ray.o - center;
    double 		a 		= ray.d * ray.d;
    double 		b 		= temp * ray.d * 2.0;
    double 		c 		= temp * temp - radius * radius;
    double 		disc	= b * b - 4.0 * a * c;
    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;

        if (t > kEpsilon) {
            tmin = t;
            sr.normal 	 = (temp + ray.d * t) / radius;
            sr.hit_point = ray.o + ray.d * t;
            return true;
        }

        t = (-b + e) / denom;

        if (t > kEpsilon) {
            tmin = t;
            sr.normal   = (temp + ray.d * t) / radius;
            sr.hit_point = ray.o + ray.d * t;
            return true;
        }
    }

    return false;
}

bool
Sphere::shadow_hit(const Ray &ray, float &tmin) const {
    if (!shadows) {
        return false;
    }
    double 		t;
    Vector3D	temp 	= ray.o - center;
    double 		a 		= ray.d * ray.d;
    double 		b 		= temp * ray.d * 2.0;
    double 		c 		= temp * temp - radius * radius;
    double 		disc	= b * b - 4.0 * a * c;
    if (disc < 0.0) {
        return false;
    }
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;
        t = (-b - e) / denom;
        if (t > kEpsilon) {
            tmin = t;
            return true;
        }
        t = (-b + e) / denom;
        if (t > kEpsilon) {
            tmin = t;
            return true;
        }
    }
    return false;
}