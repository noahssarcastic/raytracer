//
// Created by ninig on 4/19/2020.
//

#ifndef _RAYCAST_H
#define _RAYCAST_H

#include "Tracer.h"


class RayCast: public Tracer {
public:
    RayCast();
    explicit RayCast(World* _worldPtr);
    ~RayCast() override;

    RGBColor
    trace_ray(const Ray& ray) const override;

    RGBColor
    trace_ray(Ray ray, int depth) const override;
};


#endif //_RAYCAST_H
