//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_TRACER_H
#define RAYTRACER_TRACER_H

#include "Ray.h"
#include "RGBColor.h"


class World;

class Tracer {
public:
    Tracer(void);
    Tracer(World* _world_ptr);

    virtual
    ~Tracer(void);

    virtual RGBColor
    trace_ray(const Ray& ray) const;

    virtual RGBColor
    trace_ray(const Ray ray, const int depth) const;

protected:
    World* world_ptr;
};


#endif //RAYTRACER_TRACER_H
