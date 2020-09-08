//
// Created by ninig on 4/18/2020.
//

#include "BRDF.h"
#include "Constants.h"


BRDF::BRDF(): sampler_ptr(nullptr) {}

BRDF::BRDF(const BRDF& b): sampler_ptr(b.sampler_ptr) {}

BRDF::~BRDF() = default;

BRDF&
BRDF::operator=(const BRDF& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

RGBColor
BRDF::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const {
    return BLACK;
}

RGBColor
BRDF::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wi) const {
    return BLACK;
}

RGBColor
BRDF::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return BLACK;
}