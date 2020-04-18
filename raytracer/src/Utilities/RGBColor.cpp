//
// Created by ninig on 4/11/2020.
//

#include "RGBColor.h"
#include <math.h>

RGBColor::RGBColor(void): r(0.0), g(0.0), b(0.0) {}

RGBColor::RGBColor(float c): r(c), g(c), b(c) {}

RGBColor::RGBColor(float _r, float _g, float _b): r(_r), g(_g), b(_b) {}

RGBColor::RGBColor(const RGBColor& c): r(c.r), g(c.g), b(c.b) {}

RGBColor::~RGBColor(void) {}

RGBColor&
RGBColor::operator= (const RGBColor& rhs) {
    if (this == &rhs)
        return *this;
    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
    return *this;
}

RGBColor
RGBColor::operator+ (const RGBColor& c) const {
    return RGBColor(r + c.r, g + c.g, b + c.b);
}

RGBColor&
RGBColor::operator+= (const RGBColor& c) {
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

RGBColor
RGBColor::operator* (const float a) const {
    return RGBColor(r * a, g * a, b * a);
}

RGBColor&
RGBColor::operator*= (const float a) {
    r *= a;
    g *= a;
    b *= a;
    return *this;
}

RGBColor
RGBColor::operator/ (const float a) const {
    return RGBColor(r / a, g / a, b / a);
}

RGBColor&
RGBColor::operator/= (const float a) {
    r /= a;
    g /= a;
    b /= a;
    return *this;
}

RGBColor
RGBColor::operator* (const RGBColor& c) const {
    return RGBColor(r * c.r, g * c.g, b * c.b);
}

bool
RGBColor::operator== (const RGBColor& c) const {
    return r == c.r && g == c.g && b == c.b;
}

RGBColor
RGBColor::powc(float p) const {
    return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}


float
RGBColor::average(void) const {
    return (0.333333333333 * (r + g + b));
}