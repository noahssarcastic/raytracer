//
// Created by ninig on 4/19/2020.
//

#include "World.h"
#include "ShadeRec.h"
#include "Material.h"
#include "RayCast.h"


RayCast::RayCast(): Tracer() {}

RayCast::RayCast(World* _worldPtr): Tracer(_worldPtr) {}

RayCast::~RayCast() = default;

RGBColor
RayCast::trace_ray(const Ray& ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));

    if (sr.hit) {
        sr.ray = ray;			// used for specular shading
        return (sr.material_ptr->shade(sr));
    }
    else
        return (world_ptr->background_color);
}

RGBColor
RayCast::trace_ray(const Ray ray, const int depth) const {
    ShadeRec sr(world_ptr->hit_objects(ray));

    if (sr.hit) {
        sr.ray = ray;
        return (sr.material_ptr->shade(sr));
    }
    else
        return (world_ptr->background_color);
}