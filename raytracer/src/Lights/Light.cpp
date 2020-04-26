//
// Created by ninig on 4/19/2020.
//

#include <Constants.h>
#include "Light.h"


Light::Light(): shadows(false) {}

Light::Light(const Light& ls): shadows(ls.shadows) {}

Light::~Light() = default;

Light&
Light::operator= (const Light& rhs) {
    if (this == &rhs)
        return *this;
    shadows = rhs.shadows;
    return *this;
}

RGBColor
Light::L(ShadeRec& s) {
    return BLACK;
}

void
Light::set_shadows(bool s) {
    shadows = s;
}

bool
Light::in_shadow(const Ray &ray, const ShadeRec &sr) const {
    return false;
}

bool
Light::casts_shadows() const {
    return shadows;
}
