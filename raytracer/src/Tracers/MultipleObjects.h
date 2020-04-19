//
// Created by ninig on 4/13/2020.
//

#ifndef _MULTIPLEOBJECTS_H
#define _MULTIPLEOBJECTS_H

#include "Tracer.h"


/**
 * Tracer designed to handle multiple objects.
 */
class MultipleObjects: public Tracer {
public:
    MultipleObjects();
    explicit MultipleObjects(World* _worldPtr);
    ~MultipleObjects() override;

    RGBColor
    trace_ray(const Ray& ray) const override;
};


#endif //_MULTIPLEOBJECTS_H
