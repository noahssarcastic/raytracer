//
// Created by ninig on 4/26/2020.
//

#ifndef _WHITTED_H
#define _WHITTED_H

#include "Tracer.h"


class Whitted: public Tracer {
public:
    Whitted();
    explicit Whitted(World* _world_ptr);

    ~Whitted() override;

    RGBColor
    trace_ray(Ray ray, int depth) const override;
};


#endif //_WHITTED_H
