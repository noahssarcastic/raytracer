//
// Created by ninig on 4/12/2020.
//

#include "Tracer.h"
#include "Constants.h"


Tracer::Tracer(): world_ptr(nullptr) {}

Tracer::Tracer(World* _world_ptr): world_ptr(_world_ptr) {}

Tracer::~Tracer() {
    if (world_ptr)
        world_ptr = nullptr;
}

RGBColor
Tracer::trace_ray(const Ray& ray) const {
    return BLACK;
}

RGBColor
Tracer::trace_ray(const Ray ray, const int depth) const {
    return BLACK;
}

RGBColor Tracer::trace_ray(const Ray ray, float &tmin, const int depth) const {
    return BLACK;
}
