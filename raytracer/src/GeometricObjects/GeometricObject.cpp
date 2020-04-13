//
// Created by ninig on 4/11/2020.
//

#include "GeometricObject.h"
#include "Constants.h"


GeometricObject::GeometricObject(void): color(BLACK) {}

GeometricObject::GeometricObject(const GeometricObject& object): color(object.color) {}

GeometricObject::~GeometricObject(void) {}

GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
    if (this == &rhs)
        return *this;
    color = rhs.color;
    return *this;
}

void
GeometricObject::set_color(const RGBColor& c) {
    color = c;
}

void
GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

RGBColor
GeometricObject::get_color(void) {
    return color;
}