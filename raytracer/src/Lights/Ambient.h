//
// Created by ninig on 4/19/2020.
//

#ifndef _AMBIENT_H
#define _AMBIENT_H

#include "Light.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "ShadeRec.h"


class Ambient: public Light {
public:
    Ambient();
    Ambient(const Ambient& a);
    ~Ambient() override;

    Light*
    clone() const override;

    Ambient&
    operator= (const Ambient& rhs);

    void
    set_color(float c);

    void
    set_color(const RGBColor& c);

    void
    set_color(float r, float g, float b);

    Vector3D
    get_direction(ShadeRec& s) override;

    RGBColor
    L(ShadeRec& s) override;

    void
    scale_radiance(const float b);

private:
    float		ls;
    RGBColor	color;
};


#endif //_AMBIENT_H
