//
// Created by ninig on 4/26/2020.
//

#include <Material.h>
#include <Constants.h>
#include "Whitted.h"


Whitted::Whitted() = default;

Whitted::Whitted(World *_world_ptr): Tracer(_world_ptr) {}

Whitted::~Whitted() = default;

RGBColor Whitted::trace_ray(Ray ray, int depth) const {
    if (depth > world_ptr->vp.max_bounces) {
        return BLACK;
    } else {
        ShadeRec sr(world_ptr->hit_objects(ray));
        if (sr.hit) {
            sr.depth = depth;
            sr.ray = ray;
            return sr.material_ptr->shade(sr);
        } else {
            return world_ptr->background_color;
        }
    }
}