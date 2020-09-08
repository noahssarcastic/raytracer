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
    GeometricObject();
    GeometricObject(const GeometricObject& object);

    virtual
    ~GeometricObject();

    virtual GeometricObject*
    clone() const = 0;

    /**
     * Abstract hit method for geometry.
     * @param ray Ray used for collision calculation.
     * @param t Linear function parameter.
     * @param s ShadeRec for shading calculation.
     * @return true if there is a collision.
     */
    virtual bool
    hit(const Ray& ray, double& t, ShadeRec& s) = 0;

    virtual bool
    shadow_hit(const Ray& ray, float& tmin) = 0;

    Material*
    get_material() const;

    virtual void
    set_material(Material* ptr);

    void
    set_shadows(bool s);

protected:
    Material* material_ptr;
    bool shadows;

    GeometricObject&
    operator=(const GeometricObject& rhs);
};


#endif //RAYTRACER_GEOMETRICOBJECT_H
