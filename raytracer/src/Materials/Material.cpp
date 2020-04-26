//
// Created by ninig on 4/19/2020.
//

#include <Constants.h>
#include "Material.h"


Material::Material() {}

Material::Material(const Material& material) = default;

Material::~Material() = default;

RGBColor
Material::shade(ShadeRec& sr) {
    return BLACK;
}

Material&
Material::operator=(const Material& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

void Material::set_shadows(bool s) {
    shadows = s;
}
