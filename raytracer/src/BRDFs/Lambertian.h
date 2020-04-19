//
// Created by ninig on 4/18/2020.
//

#ifndef _LAMBERTIAN_H
#define _LAMBERTIAN_H

#include "BRDF.h"


/**
 * Simulates diffuse reflection.
 * Best for simulating matte materials.
 */
class Lambertian: public BRDF {
public:
    Lambertian(void);
    Lambertian(const Lambertian& lamb);
    ~Lambertian(void);

    virtual Lambertian*
    clone(void) const;

    Lambertian&
    operator= (const Lambertian& rhs);

    /**
     * Computer lambertian diffuse shading.
     * @param sr Shaderec for calculation storage.
     * @param wo Incoming unit Vector3D direction.
     * @param wi Outgoing unit Vector3D direction.
     * @return
     */
    virtual RGBColor
    f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;

    virtual RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const;

    void
    set_kd(const float k);

    void
    set_cd(const RGBColor& c);

    void
    set_cd(const float r, const float g, const float b);

    void
    set_cd(const float c);

private:
    float		kd; /**< Diffuse coefficient. */
    RGBColor 	cd; /**< Diffuse color. */
};


#endif //_LAMBERTIAN_H
