//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_GEOMETRICOBJECT_H
#define RAYTRACER_GEOMETRICOBJECT_H

#include <Ray.h>
#include "RGBColor.h"
#include "ShadeRec.h"

/**
 * Abstract class representing a geometry.
 */
class GeometricObject {
public:
    GeometricObject(void);
    GeometricObject(const GeometricObject& object);

    virtual
    ~GeometricObject(void);

    virtual GeometricObject*
    clone(void) const = 0;

    /**
     * Abstract hit method for geometry.
     * @param ray Ray used for collision calculation.
     * @param t Linear function parameter.
     * @param s ShadeRec for shading calculation.
     * @return true if there is a collision.
     */
    virtual bool
    hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

    void
    set_color(const RGBColor& c);

    void
    set_color(const float r, const float g, const float b);

    RGBColor
    get_color(void);

protected:
    RGBColor color;

    GeometricObject&
    operator=(const GeometricObject& rhs);
};


#endif //RAYTRACER_GEOMETRICOBJECT_H
