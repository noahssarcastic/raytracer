//
// Created by ninig on 4/19/2020.
//

#include <Constants.h>
#include "Light.h"


Light::Light() = default;

Light::Light(const Light& ls) = default;

Light::~Light() = default;

Light&
Light::operator= (const Light& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

RGBColor
Light::L(ShadeRec& s) {
    return BLACK;
}