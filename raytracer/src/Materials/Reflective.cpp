//
// Created by ninig on 4/26/2020.
//

#include "Reflective.h"


Reflective::Reflective(): Phong(), reflective_brdf(new PerfectSpecular) {}

Reflective::Reflective(const Reflective &r): Phong(r), reflective_brdf(r.reflective_brdf) {}

Reflective::~Reflective() {
    if (reflective_brdf)
        reflective_brdf = nullptr;
}

Reflective*
Reflective::clone() const {
    return new Reflective(*this);
}

RGBColor Reflective::shade(ShadeRec &sr) {
    RGBColor L(Phong::shade(sr));
    Vector3D wo = -sr.ray.d;
    Vector3D wi;
    RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);
    Ray reflected(sr.hit_point, wi);
    L += fr * sr.w.tracer_ptr->trace_ray(reflected, sr.depth + 1) * (sr.normal * wi);
    return L;
}

void Reflective::set_kr(float k) {
    reflective_brdf->set_kr(k);
}

void Reflective::set_cr(RGBColor c) {
    reflective_brdf->set_cr(c);
}

void Reflective::set_cr(float r, float g, float b) {
    reflective_brdf->set_cr(r, g, b);
}

void Reflective::set_cr(float c) {
    reflective_brdf->set_cr(c);
}
