//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_SHADEREC_H
#define RAYTRACER_SHADEREC_H

#include "Point3D.h"
#include "Normal.h"
#include "RGBColor.h"


class World;

class ShadeRec {
public:
    bool hit;
    Point3D hit_point;
    Normal normal;
    RGBColor color;
    World& w;

    ShadeRec(World& _w);
    ShadeRec(const ShadeRec& sr);
};


#endif //RAYTRACER_SHADEREC_H
