//
// Created by ninig on 4/11/2020.
//

#include "Sphere.h"


Sphere(void);

Sphere(Point3D center, double r);

Sphere(const Sphere& sphere);

virtual
~Sphere(void);

virtual Sphere*
clone(void) const;

Sphere&
operator= (const Sphere& sphere);

void
set_center(const Point3D& c);

void
set_center(const double x, const double y, const double z);

void
set_radius(const double r);

virtual bool
hit(const Ray& ray, double& t, ShadeRec& s) const;