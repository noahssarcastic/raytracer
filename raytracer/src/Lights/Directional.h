//
// Created by ninig on 4/19/2020.
//

#ifndef _DIRECTIONAL_H
#define _DIRECTIONAL_H

#include "Light.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "World.h"
#include "ShadeRec.h"


class Directional: public Light {
public:
    Directional();
    Directional(const Directional& dl);
    ~Directional() override;

    Light*
    clone() const override;

    Directional&
    operator=(const Directional& rhs);

    void
    set_color(float c);

    void
    set_color(const RGBColor& c);

    void
    set_color(float r, float g, float b);

    void
    set_direction(Vector3D d);

    void
    set_direction(float dx, float dy, float dz);

    Vector3D
    get_direction(ShadeRec& sr) override;

    RGBColor
    L(ShadeRec& sr) override;

    void
    scale_radiance(float b);

    bool
    in_shadow(const Ray& ray, const ShadeRec& sr) const override;

private:
    float		ls;
    RGBColor	color;
    Vector3D	dir;
};


#endif //_DIRECTIONAL_H
