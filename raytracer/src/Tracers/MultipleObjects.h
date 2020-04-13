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
    MultipleObjects(World* _worldPtr);

    virtual
    ~MultipleObjects();

    virtual RGBColor
    trace_ray(const Ray& ray) const;
};


#endif //_MULTIPLEOBJECTS_H
