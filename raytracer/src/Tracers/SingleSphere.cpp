//
// Created by ninig on 4/12/2020.
//

#include "SingleSphere.h"
#include "World.h"
#include "ShadeRec.h"
#include "Constants.h"


SingleSphere::SingleSphere(void): Tracer() {}

SingleSphere::SingleSphere(World* _worldPtr): Tracer(_worldPtr) {}

SingleSphere::~SingleSphere(void) {}

RGBColor
SingleSphere::trace_ray(const Ray& ray) const {
    ShadeRec	sr(*world_ptr);
    double    	t;
    if (world_ptr->sphere.hit(ray, t, sr)) {
        return (RED);
    }
    else {
        return (BLACK);
    }
}