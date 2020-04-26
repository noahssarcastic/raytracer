//
// Created by ninig on 4/12/2020.
//

#include "ShadeRec.h"


ShadeRec::ShadeRec(World& _w):
    hit(false),
    material_ptr(nullptr),
    hit_point(),
    local_hit_point(),
    normal(),
    ray(),
    depth(0),
    t(0.0),
    dir(),
    w(_w)
    {}

ShadeRec::ShadeRec(const ShadeRec& sr):
    hit(sr.hit),
    material_ptr(sr.material_ptr),
    hit_point(sr.hit_point),
    local_hit_point(sr.local_hit_point),
    normal(sr.normal),
    ray(sr.ray),
    depth(sr.depth),
    t(sr.t),
    dir(sr.dir),
    w(sr.w)
    {}
