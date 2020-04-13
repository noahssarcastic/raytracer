//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include "GeometricObject.h"
#include "Point3D.h"


class Plane: public GeometricObject {
public:
    Plane(void);
    Plane(const Point3D p, const Normal& _n);
    Plane(const Plane& plane);

    virtual
    ~Plane(void);

    virtual Plane*
    clone(void) const;

    Plane&
    operator= (const Plane& rhs);

    virtual bool
    hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

private:
    Point3D a;
    Normal n;
    static const double kEpsilon;
};


#endif //RAYTRACER_PLANE_H
