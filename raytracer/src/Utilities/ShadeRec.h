//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_SHADEREC_H
#define RAYTRACER_SHADEREC_H

#include <Ray.h>
#include "Point3D.h"
#include "Normal.h"
#include "RGBColor.h"


class Material;
class World;

/**
 * Class used to store rudimentary shading data.
 */
class ShadeRec {
public:
    bool hit;
    Material* material_ptr;
    Point3D hit_point;
    Point3D local_hit_point;
    Normal normal;
    Ray ray;
    int depth;
    float t;
    Vector3D dir;
    World& w;

    explicit ShadeRec(World& _w);
    ShadeRec(const ShadeRec& sr);
};


#endif //RAYTRACER_SHADEREC_H
