//
// Created by ninig on 4/12/2020.
//

#include "ShadeRec.h"
#include "Constants.h"


ShadeRec::ShadeRec(World& _w): hit(false), hit_point(), normal(), color(BLACK), w(_w) {}

ShadeRec::ShadeRec(const ShadeRec& sr):
    hit(sr.hit),
    hit_point(sr.hit_point),
    normal(sr.normal),
    color(sr.color),
    w(sr.w) {}
