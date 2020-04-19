//
// Created by ninig on 4/19/2020.
//

#ifndef _MATERIAL_H
#define _MATERIAL_H


#include "World.h"
#include "RGBColor.h"
#include <ShadeRec.h>

class Material {
public:
    Material();
    Material(const Material& material);

    virtual
    ~Material();

    virtual Material*
    clone() const = 0;

    virtual RGBColor
    shade(ShadeRec& sr);

protected:
    Material&
    operator= (const Material& rhs);
};


#endif //_MATERIAL_H
