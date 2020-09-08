//
// Created by ninig on 4/28/2020.
//

#include "Polished.h"


Polished::Polished(): Material(), reflective_brdf(new PerfectSpecular) {}

Polished::Polished(const Polished &p): Material(p), reflective_brdf(p.reflective_brdf) {}

Polished::~Polished() {
    if (reflective_brdf)
        reflective_brdf = nullptr;
}

Material*
Polished::clone() const {
    return new Polished(*this);
}

RGBColor Polished::shade(ShadeRec &sr) {
    RGBColor L;
    Vector3D wo = -sr.ray.d;
    Vector3D wi;
    RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);
    Ray reflected(sr.hit_point, wi);
    L = fr * sr.w.tracer_ptr->trace_ray(reflected, sr.depth + 1) * (sr.normal * wi);
    return L;
}

void Polished::set_kr(float k) {
    reflective_brdf->set_kr(k);
}

void Polished::set_cr(const RGBColor& c) {
    reflective_brdf->set_cr(c);
}

void Polished::set_cr(float r, float g, float b) {
    reflective_brdf->set_cr(r, g, b);
}

void Polished::set_cr(float c) {
    reflective_brdf->set_cr(c);
}
