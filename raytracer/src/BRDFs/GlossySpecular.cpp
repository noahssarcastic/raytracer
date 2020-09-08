//
// Created by ninig on 4/19/2020.
//

#include <cmath>
#include <Constants.h>
#include "GlossySpecular.h"


GlossySpecular::GlossySpecular(): BRDF(), ks(0.0), cs(1.0), exp(5), sampler() {}

GlossySpecular::~GlossySpecular() = default;

GlossySpecular*
GlossySpecular::clone() const {
    return new GlossySpecular(*this);
}

RGBColor
GlossySpecular::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const {
    RGBColor L;
    float normal_check = sr.normal * wi;
    Vector3D r(-wi + sr.normal * 2.0 * normal_check);
    float visibility = r * wo;
    if (visibility > 0.0)
        L = cs * ks * pow(visibility, exp);
    return L;
}

RGBColor
GlossySpecular::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return BLACK;
}

void
GlossySpecular::set_ks(const float _ks) {
    ks = _ks;
}

void
GlossySpecular::set_exp(const float e) {
    exp = e;
}

void
GlossySpecular::set_cs(const RGBColor& c) {
    cs = c;
}

void
GlossySpecular::set_cs(const float r, const float g, const float b) {
    cs.r = r;
    cs.g = g;
    cs.b = b;
}

void
GlossySpecular::set_cs(const float c) {
    cs.r = c;
    cs.g = c;
    cs.b = c;
}