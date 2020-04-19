//
// Created by ninig on 4/18/2020.
//

#include "BRDF.h"
#include "Constants.h"


BRDF::BRDF() {}

BRDF::BRDF(const BRDF& object) {}

BRDF::~BRDF() {}

BRDF&
BRDF::operator=(const BRDF& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

virtual RGBColor
BRDF::f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
    return BLACK;
}

virtual RGBColor
BRDF::sample_f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const {
    return BLACK;
}

virtual RGBColor
BRDF::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return BLACK;
}