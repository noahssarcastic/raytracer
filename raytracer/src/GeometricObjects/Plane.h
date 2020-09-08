//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include "GeometricObject.h"
#include "Point3D.h"


/**
 * GeometricObject representing a plane.
 */
class Plane: public GeometricObject {
public:
    Plane();
    Plane(Point3D p, const Normal& _n);
    Plane(const Plane& plane);


    ~Plane() override;

    Plane*
    clone() const override;

    Plane&
    operator= (const Plane& rhs);

    bool
    hit(const Ray& ray, double& tmin, ShadeRec& sr) override;

    bool
    shadow_hit(const Ray& ray, float& tmin) override;

private:
    Point3D a;
    Normal n;
    static const double kEpsilon;
};


#endif //RAYTRACER_PLANE_H
