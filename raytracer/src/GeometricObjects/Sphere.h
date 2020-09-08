//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "GeometricObject.h"
#include "Point3D.h"


/**
 * Geometric Object representing a sphere.
 */
class Sphere: public GeometricObject {
public:
    Sphere();
    Sphere(Point3D c, double r);
    Sphere(const Sphere& sphere);
    ~Sphere() override;

    Sphere*
    clone() const override;

    Sphere&
    operator= (const Sphere& sphere);

    void
    set_center(const Point3D& c);

    void
    set_center(double x, double y, double z);

    void
    set_radius(double r);

    bool
    hit(const Ray& ray, double& t, ShadeRec& sr) override;

    bool
    shadow_hit(const Ray &ray, float &tmin) override;

private:
    Point3D 	        center;
    double 		        radius;
    static const double kEpsilon;
};


#endif //RAYTRACER_SPHERE_H
