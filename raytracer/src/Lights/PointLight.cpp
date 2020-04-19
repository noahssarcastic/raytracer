//
// Created by ninig on 4/19/2020.
//

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
