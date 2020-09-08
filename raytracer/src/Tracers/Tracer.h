//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_TRACER_H
#define RAYTRACER_TRACER_H

#include "Ray.h"
#include "RGBColor.h"


class World;

/**
 * Abstract class designed to handle all raycasts in a World.
 */
class Tracer {
public:
    Tracer();
    explicit Tracer(World* _world_ptr);

    virtual
    ~Tracer();

    /**
     * Given a ray, cast to all objects, set ShadeRec data, and return a pixel color.
     * @param ray Ray to cast.
     * @return RGBColor representing the color value of the given intersection.
     */
    virtual RGBColor
    trace_ray(const Ray& ray) const;

    virtual RGBColor
    trace_ray(Ray ray, int depth) const;

    virtual RGBColor
    trace_ray(Ray ray, float& tmin, int depth) const;

protected:
    World* world_ptr;
};


#endif //RAYTRACER_TRACER_H
