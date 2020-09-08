//
// Created by ninig on 4/28/2020.
// cs = cd
//

#ifndef _METALLIC_H
#define _METALLIC_H

#include <Lambertian.h>
#include <GlossySpecular.h>
#include "Material.h"


class Metallic: public Material {
public:
    Metallic();

    Metallic(const Metallic& m);

    ~Metallic() override;

    Metallic*
    clone() const override;

    void
    set_ka(float k);

    void
    set_kd(float k);

    void
    set_c(RGBColor c);

    void
    set_c(float r, float g, float b);

    void
    set_c(float c);

    void
    set_ks(float ks);

    void
    set_exp(float exp);

    RGBColor
    shade(ShadeRec& sr) override;

protected:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular* specular_brdf;
};


#endif //_METALLIC_H
