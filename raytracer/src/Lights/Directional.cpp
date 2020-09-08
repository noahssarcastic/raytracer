//
// Created by ninig on 4/19/2020.
//

#include "Directional.h"


Directional::Directional(): Light(), ls(1.0), color(1.0), dir(0, 1, 0) {}

Directional::Directional(const Directional& dl): Light(dl), ls(dl.ls), color(dl.color), dir(dl.dir) {}

Directional::~Directional() = default;

Light*
Directional::clone() const {
    return new Directional(*this);
}

Directional&
Directional::operator=(const Directional& rhs) {
    if (this == &rhs)
        return *this;
    Light::operator=(rhs);
    ls = rhs.ls;
    color = rhs.color;
    dir = rhs.dir;
    return *this;
}

void
Directional::set_color(const float c) {
    color.r = c;
    color.g = c;
    color.b = c;
}

void
Directional::set_color(const RGBColor& c) {
    color = c;
}

void
Directional::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

void
Directional::set_direction(Vector3D d) {
    dir = d;
}

void
Directional::set_direction(float dx, float dy, float dz) {
    dir.x = dx;
    dir.y = dy;
    dir.z = dz;
}

Vector3D
Directional::get_direction(ShadeRec& sr) {
    return -dir.hat();
}

RGBColor
Directional::L(ShadeRec& sr) {
    return color * ls;
}

void Directional::scale_radiance(const float b) {
    ls = b;
}

bool Directional::in_shadow(const Ray &ray, const ShadeRec &sr) const {
    if (!shadows) {
        return false;
    }
    float t;
    int num_objects = sr.w.objects.size();
    for (int i = 0; i < num_objects; i++) {
        if (sr.w.objects[i]->shadow_hit(ray, t)) {
            return true;
        }
    }
    return false;
}
