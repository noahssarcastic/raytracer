//
// Created by ninig on 4/26/2020.
//

#ifndef _REFLECTIVE_H
#define _REFLECTIVE_H

#include <PerfectSpecular.h>
#include "Phong.h"


class Reflective: public Phong {
public:
    Reflective();
    explicit Reflective(const Reflective& r);
    ~Reflective() override;

    Reflective*
    clone() const override;

    RGBColor
    shade(ShadeRec& sr) override;

    void
    set_kr(float k);

    void
    set_cr(RGBColor c);

    void
    set_cr(float r, float g, float b);

    void
    set_cr(float c);

private:
    PerfectSpecular* reflective_brdf;
};


#endif //_REFLECTIVE_H
