//
// Created by ninig on 4/28/2020.
//

#include "Metallic.h"


Metallic::Metallic():
        Material(),
        ambient_brdf(new Lambertian),
        diffuse_brdf(new Lambertian),
        specular_brdf(new GlossySpecular)
{}

Metallic::Metallic(const Metallic &m):
        Material(m),
        ambient_brdf(m.ambient_brdf),
        diffuse_brdf(m.diffuse_brdf),
        specular_brdf(m.specular_brdf)
{}

Metallic::~Metallic() {
    if (ambient_brdf)
        ambient_brdf = nullptr;
    if (diffuse_brdf)
        diffuse_brdf = nullptr;
    if (specular_brdf)
        specular_brdf = nullptr;
}

RGBColor
Metallic::shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();
    for (int i = 0; i < num_lights; i++) {
        Vector3D wi = sr.w.lights[i]->get_direction(sr);
        float normal_check = sr.normal * wi;
        if (normal_check > 0.0) {
            bool in_shadow = false;
            if (sr.w.lights[i]->casts_shadows()) {
                Ray shadowRay(sr.hit_point, wi);
                in_shadow = sr.w.lights[i]->in_shadow(shadowRay, sr);
            }
            if (!in_shadow) {
                RGBColor shade = (diffuse_brdf->f(sr, wo, wi) + specular_brdf->f(sr, wo, wi));
                L +=  shade * sr.w.lights[i]->L(sr) * normal_check;
            }
        }
    }
    return L;
}

Metallic*
Metallic::clone() const {
    return new Metallic(*this);
}

void
Metallic::set_ka(float k) {
    ambient_brdf->set_kd(k);
}

void
Metallic::set_kd(float k) {
    diffuse_brdf->set_kd(k);
}

void
Metallic::set_c(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
    specular_brdf->set_cs(c);
}

void
Metallic::set_c(float r, float g, float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
    specular_brdf->set_cs(r, g, b);
}

void
Metallic::set_c(float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
    specular_brdf->set_cs(c);
}

void
Metallic::set_ks(float ks) {
    specular_brdf->set_ks(ks);
}

void
Metallic::set_exp(float exp) {
    specular_brdf->set_exp(exp);
}