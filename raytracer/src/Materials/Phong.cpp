//
// Created by ninig on 4/19/2020.
//

#include "Phong.h"


Phong::Phong():
    Material(),
    ambient_brdf(new Lambertian),
    diffuse_brdf(new Lambertian),
    specular_brdf(new GlossySpecular)
    {}

RGBColor
Phong::shade(ShadeRec& sr) {
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

Material*
Phong::clone() const {
    return new Phong(*this);
}

void
Phong::set_ka(float k) {
    ambient_brdf->set_kd(k);
}

void
Phong::set_kd(float k) {
    diffuse_brdf->set_kd(k);
}

void
Phong::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

void
Phong::set_cd(float r, float g, float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

void
Phong::set_cd(float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

void
Phong::set_ks(float ks) {
    specular_brdf->set_ks(ks);
}

void
Phong::set_exp(float exp) {
    specular_brdf->set_exp(exp);
}

void
Phong::set_cs(const RGBColor& c) {
    specular_brdf->set_cs(c);
}

void
Phong::set_cs(float r, float g, float b) {
    specular_brdf->set_cs(r, g, b);
}

void
Phong::set_cs(float c) {
    specular_brdf->set_cs(c);
}

