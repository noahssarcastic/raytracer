//
// Created by ninig on 4/26/2020.
//

#ifndef _PERFECTSPECULAR_H
#define _PERFECTSPECULAR_H

#include "BRDF.h"


class PerfectSpecular: public BRDF {
public:
    PerfectSpecular();
    PerfectSpecular(const PerfectSpecular& p);
    ~PerfectSpecular();

    PerfectSpecular*
    clone() const override;

    PerfectSpecular&
    operator= (const PerfectSpecular& rhs);

    RGBColor
    sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi) const override;

    void
    set_kr(float k);

    void
    set_cr(const RGBColor& c);

    void
    set_cr(float r, float g, float b);

    void
    set_cr(float c);

private:
    float kr;
    RGBColor cr;
};


#endif //_PERFECTSPECULAR_H
