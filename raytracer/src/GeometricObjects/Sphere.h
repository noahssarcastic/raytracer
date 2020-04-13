//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "GeometricObject.h"
#include "Point3D.h"


class Sphere: public GeometricObject {
public:
    Sphere(void);
    Sphere(Point3D c, double r);
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
    hit(const Ray& ray, double& t, ShadeRec& sr) const;

private:
    Point3D 	        center;
    double 		        radius;
    static const double kEpsilon;
};


#endif //RAYTRACER_SPHERE_H
