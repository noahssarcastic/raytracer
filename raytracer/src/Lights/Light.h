//
// Created by ninig on 4/19/2020.
//

#ifndef _LIGHT_H
#define _LIGHT_H

#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"


class ShadeRec;

class Light {
public:
    Light();
    Light(const Light& ls);

    virtual
    ~Light();

    Light&
    operator= (const Light& rhs);

    virtual Light*
    clone() const = 0;

    virtual Vector3D
    get_direction(ShadeRec& sr) = 0;

    virtual RGBColor
    L(ShadeRec& sr);

    virtual bool
    in_shadow(const Ray& ray, const ShadeRec& sr) const;

    void
    set_shadows(bool s);

    bool
    casts_shadows() const;

protected:
    bool shadows;
};


#endif //_LIGHT_H
