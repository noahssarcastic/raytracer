//
// Created by ninig on 4/19/2020.
//

#include "Matte.h"
#include <iostream>


Matte::Matte(): Material(), ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian) {}

Matte::Matte(const Matte& m): Material(m), ambient_brdf(m.ambient_brdf), diffuse_brdf(m.diffuse_brdf) {}

Matte::~Matte() {
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = nullptr;
    }
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = nullptr;
    }
}

Matte&
Matte::operator=(const Matte& rhs) {
    if (this == &rhs)
        return *this;
    Material::operator=(rhs);
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = nullptr;
    }
    if (rhs.ambient_brdf)
        ambient_brdf = rhs.ambient_brdf->clone();
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = nullptr;
    }
    if (rhs.diffuse_brdf)
        diffuse_brdf = rhs.diffuse_brdf->clone();
    return *this;
}

Material*
Matte::clone() const {
    return new Matte(*this);
}

void
Matte::set_ka(const float k) {
    ambient_brdf->set_kd(k);
}

void
Matte::set_kd(const float k) {
    diffuse_brdf->set_kd(k);
}

void
Matte::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

void
Matte::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

void
Matte::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

RGBColor
Matte::shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();
    for (int i = 0; i < num_lights; i++) {
        Vector3D wi = sr.w.lights[i]->get_direction(sr);
        float normal_check = sr.normal * wi;
//        std::cout << "n" << normal_check << "\n";
        if (normal_check > 0.0) {
            bool in_shadow = false;
            if (shadows && sr.w.lights[i]->casts_shadows()) {
//                std::cout << "casts shadows\n";
                Ray shadowRay(sr.hit_point, wi);
                in_shadow = sr.w.lights[i]->in_shadow(shadowRay, sr);
            }
            if (!in_shadow) {
//                std::cout << "not in shadow\n";
                L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[i]->L(sr) * normal_check;
            }
        }
    }
//    std::cout << "r" << L.r << "g" << L.r << "b" << L.r << "\n";
    return L;
}