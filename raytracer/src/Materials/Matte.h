//
// Created by ninig on 4/19/2020.
//

#ifndef _MATTE_H
#define _MATTE_H

#include <Lambertian.h>
#include "Material.h"


class Matte: public Material {
public:
    Matte();
    Matte(const Matte& m);
    ~Matte() override;

    Matte&
    operator= (const Matte& rhs);

    Material*
    clone() const override;

    void
    set_ka(float k);

    void
    set_kd(float k);

    void
    set_cd(const RGBColor c);

    void
    set_cd(float r, float g, float b);

    void
    set_cd(float c);

    virtual RGBColor
    shade(ShadeRec& sr);

private:
    Lambertian*		ambient_brdf;
    Lambertian*		diffuse_brdf;
};


#endif //_MATTE_H
