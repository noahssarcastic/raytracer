//
// Created by ninig on 4/28/2020.
//

#include "BlinnPhong.h"

BlinnPhong::BlinnPhong(): GlossySpecular() {}

BlinnPhong::~BlinnPhong() = default;

BlinnPhong *BlinnPhong::clone() const {
    return new BlinnPhong(*this);
}

RGBColor BlinnPhong::f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const {
    return GlossySpecular::f(sr, wo, wi);
}
