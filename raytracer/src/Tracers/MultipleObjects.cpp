//
// Created by ninig on 4/13/2020.
//

#include "MultipleObjects.h"
#include "World.h"


MultipleObjects::MultipleObjects(): Tracer() {}

MultipleObjects::MultipleObjects(World* _worldPtr): Tracer(_worldPtr) {}

MultipleObjects::~MultipleObjects() = default;

RGBColor
MultipleObjects::trace_ray(const Ray& ray) const {
//    ShadeRec sr(world_ptr->hit_bare_bones_objects(ray));
//    if (sr.hit)
//        return sr.color;
//    else
//        return world_ptr->background_color;
}