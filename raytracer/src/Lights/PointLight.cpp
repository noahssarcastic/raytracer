//
// Created by ninig on 4/19/2020.
//

#include <iostream>
#include "PointLight.h"


PointLight::PointLight(): Light(), ls(1.0), color(1.0), loc(10, 10, 10) {}

PointLight::PointLight(const PointLight& pl): Light(pl), ls(pl.ls), color(pl.color), loc(pl.loc) {}

PointLight::~PointLight() {}

Light*
PointLight::clone() const {
    return new PointLight(*this);
}

PointLight&
PointLight::operator=(const PointLight& rhs) {
    if (this == &rhs)
        return *this;
    Light::operator=(rhs);
    ls = rhs.ls;
    color = rhs.color;
    loc = rhs.loc;
    return *this;
}

void
PointLight::set_color(float c) {
    color.r = c;
    color.g = c;
    color.b = c;
}

void
PointLight::set_color(const RGBColor& c) {
    color = c;
}

void
PointLight::set_color(float r, float g, float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

void
PointLight::set_location(Point3D l) {
    loc = l;
}

void
PointLight::set_location(float lx, float ly, float lz) {
    loc.x = lx;
    loc.y = ly;
    loc.z = lz;
}

Vector3D
PointLight::get_direction(ShadeRec& sr) {
    return (loc - sr.hit_point).hat();
}

RGBColor
PointLight::L(ShadeRec& sr) {
    return color * ls;
}

void PointLight::scale_radiance(const float b) {
    ls = b;
}

bool PointLight::in_shadow(const Ray &ray, const ShadeRec &sr) const {
    if (!shadows) {
        return false;
    }
    float t;
    int num_objects = sr.w.objects.size();
    float d = loc.distance(ray.o);
//    std::cout << "distance " << d << "\n";
    for (int i = 0; i < num_objects; i++) {
        GeometricObject* obj = sr.w.objects[i];
        bool shadow_hit = obj->shadow_hit(ray, t);
        if ( shadow_hit && t < d) {
//            std::cout << "shadow hit at " << t << "\n";
            return true;
        }
    }
    return false;
}
