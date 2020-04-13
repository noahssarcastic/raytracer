//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_SINGLESPHERE_H
#define RAYTRACER_SINGLESPHERE_H

#include "Tracer.h"


class SingleSphere: public Tracer {
public:
    SingleSphere(void);
    SingleSphere(World* _worldPtr);

    virtual
    ~SingleSphere(void);

    virtual RGBColor
    trace_ray(const Ray& ray) const;
};


#endif //RAYTRACER_SINGLESPHERE_H
