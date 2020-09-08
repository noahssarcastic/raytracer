//
// Created by ninig on 4/19/2020.
//

#ifndef _PHONG_H
#define _PHONG_H

#include <GlossySpecular.h>
#include <Lambertian.h>
#include "Material.h"


class Phong: public Material {
public:
    Phong();

    Phong(const Phong& p);

    ~Phong() override;

    Phong*
    clone() const override;

    void
    set_ka(float k);

    void
    set_kd(float k);

    void
    set_cd(RGBColor c);

    void
    set_cd(float r, float g, float b);

    void
    set_cd(float c);

    void
    set_ks(float ks);

    void
    set_exp(float exp);

    void
    set_cs(const RGBColor& c);

    void
    set_cs(float r, float g, float b);

    void
    set_cs(float c);

    RGBColor
    shade(ShadeRec& sr) override;

protected:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
};


#endif //_PHONG_H
