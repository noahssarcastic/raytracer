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
    Lambertian();
    Lambertian(const Lambertian& lamb);
    ~Lambertian();

    Lambertian*
    clone() const override;

    Lambertian&
    operator= (const Lambertian& rhs);

    /**
     * Computer lambertian diffuse shading.
     * @param sr Shaderec for calculation storage.
     * @param wo Incoming unit Vector3D direction.
     * @param wi Outgoing unit Vector3D direction.
     * @return
     */
    RGBColor
    f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const override;

    RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const override;

    void
    set_kd(float k);

    void
    set_cd(const RGBColor& c);

    void
    set_cd(float r, float g, float b);

    void
    set_cd(float c);

private:
    float		kd; /**< Diffuse coefficient. */
    RGBColor 	cd; /**< Diffuse color. */
};


#endif //_LAMBERTIAN_H
