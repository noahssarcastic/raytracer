//
// Created by ninig on 4/18/2020.
//

#include <Constants.h>
#include "Lambertian.h"


Lambertian::Lambertian(): BRDF(), kd(0.0), cd(0.0) {}

Lambertian::Lambertian(const Lambertian& l): BRDF(l), kd(l.kd), cd(l.cd) {}

Lambertian::~Lambertian() = default;

Lambertian*
Lambertian::clone() const {
    return new Lambertian(*this);
}

Lambertian&
Lambertian::operator=(const Lambertian& rhs) {
    if (this == &rhs)
        return *this;
    BRDF::operator=(rhs);
    kd = rhs.kd;
    cd = rhs.cd;
    return *this;
}

void
Lambertian::set_kd(const float k) {
    kd = k;
}

void
Lambertian::set_cd(const RGBColor& c) {
    cd = c;
}

void
Lambertian::set_cd(const float r, const float g, const float b) {
    cd.r = r;
    cd.g = g;
    cd.b = b;
}

void
Lambertian::set_cd(const float c){
    cd.r = c;
    cd.g = c;
    cd.b = c;
}

RGBColor
Lambertian::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const {
    return cd * kd * INV_PI;
}

RGBColor
Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {
    return cd * kd;
}
