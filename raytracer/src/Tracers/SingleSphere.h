//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_SINGLESPHERE_H
#define RAYTRACER_SINGLESPHERE_H

#include "Tracer.h"


/**
 * Tracer designed to trace a single sphere.
 */
class SingleSphere: public Tracer {
public:
    SingleSphere();
    SingleSphere(World* _worldPtr);

    virtual
    ~SingleSphere();

    virtual RGBColor
    trace_ray(const Ray& ray) const;
};


#endif //RAYTRACER_SINGLESPHERE_H
