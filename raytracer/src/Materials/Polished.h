//
// Created by ninig on 4/28/2020.
// ka = kd = ks (remove phong component)
//

#ifndef _POLISHED_H
#define _POLISHED_H

#include <PerfectSpecular.h>
#include "Material.h"


class Polished: public Material {
public:
    Polished();
    explicit Polished(const Polished& p);
    ~Polished() override;

    Material*
    clone() const override;

    RGBColor
    shade(ShadeRec& sr) override;

    void
    set_kr(float k);

    void
    set_cr(const RGBColor& c);

    void
    set_cr(float r, float g, float b);

    void
    set_cr(float c);

private:
    PerfectSpecular* reflective_brdf;
};


#endif //_POLISHED_H
