//
// Created by ninig on 4/26/2020.
//

#include <Constants.h>
#include "PerfectSpecular.h"


PerfectSpecular::PerfectSpecular(): BRDF(), kr(0.0), cr(0.0) {}

PerfectSpecular::PerfectSpecular(const PerfectSpecular &p): BRDF(p), kr(p.kr), cr(p.cr) {}

PerfectSpecular::~PerfectSpecular() = default;

PerfectSpecular
*PerfectSpecular::clone() const {
    return new PerfectSpecular(*this);
}

PerfectSpecular
&PerfectSpecular::operator=(const PerfectSpecular &rhs) {
    if (this == &rhs)
        return *this;
    BRDF::operator=(rhs);
    kr = rhs.kr;
    cr = rhs.cr;
    return *this;
}

RGBColor
PerfectSpecular::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi) const {
    float normal_check = sr.normal * wo;
    wi = -wo + sr.normal * 2.0 * normal_check;
    return cr * kr / (sr.normal * wi);
}

void
PerfectSpecular::set_kr(const float k) {
    kr = k;
}

void
PerfectSpecular::set_cr(const RGBColor& c) {
    cr = c;
}

void
PerfectSpecular::set_cr(const float r, const float g, const float b) {
    cr.r = r;
    cr.g = g;
    cr.b = b;
}

void
PerfectSpecular::set_cr(const float c){
    cr.r = c;
    cr.g = c;
    cr.b = c;
}

