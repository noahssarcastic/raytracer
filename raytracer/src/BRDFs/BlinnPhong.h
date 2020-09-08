//
// Created by ninig on 4/28/2020.
//

#ifndef _BLINNPHONG_H
#define _BLINNPHONG_H

#include "GlossySpecular.h"


class BlinnPhong: public GlossySpecular {
public:
    BlinnPhong();
    ~BlinnPhong();

    BlinnPhong*
    clone() const override;

    RGBColor
    f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const override;
};


#endif //_BLINNPHONG_H
