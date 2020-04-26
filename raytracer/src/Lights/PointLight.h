//
// Created by ninig on 4/19/2020.
//

#ifndef _POINTLIGHT_H
#define _POINTLIGHT_H

#include "Light.h"
#include "Vector3D.h"
#include "RGBColor.h"
#include "World.h"
#include "ShadeRec.h"


class PointLight: public Light {
public:
    PointLight();
    PointLight(const PointLight& pl);
    ~PointLight() override;

    Light*
    clone() const override;

    PointLight&
    operator=(const PointLight& rhs);

    void
    set_color(float c);

    void
    set_color(const RGBColor& c);

    void
    set_color(float r, float g, float b);

    void
    set_location(Point3D l);

    void
    set_location(float lx, float ly, float lz);

    Vector3D
    get_direction(ShadeRec& sr) override;

    RGBColor
    L(ShadeRec& sr) override;

    void
    scale_radiance(float b);

    bool
    in_shadow(const Ray& ray, const ShadeRec& sr) const override;

private:
    float		ls;
    RGBColor	color;
    Point3D	    loc;
};


#endif //_POINTLIGHT_H
