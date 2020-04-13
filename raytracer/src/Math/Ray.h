//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Point3D.h"


class Ray {
public:

    Point3D	 o;  // origin
    Vector3D d;  // direction

    Ray(void);
    Ray(const Point3D& origin, const Vector3D& dir);
    Ray(const Ray& ray);
    ~Ray(void);

    Ray&
    operator= (const Ray& rhs);
};


#endif //RAYTRACER_RAY_H
