//
// Created by ninig on 4/19/2020.
//

#ifndef _GLOSSYSPECULAR_H
#define _GLOSSYSPECULAR_H

#include <Normal.h>
#include <Sampler.h>
#include <RGBColor.h>
#include <ShadeRec.h>
#include "BRDF.h"


class GlossySpecular: public BRDF {
public:
    GlossySpecular();
    ~GlossySpecular();

    GlossySpecular*
    clone() const override;

    RGBColor
    f(const ShadeRec &sr, const Vector3D &wo, const Vector3D &wi) const override;

    RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const override;

    void
    set_ks(float ks);

    void
    set_exp(float exp);

    void
    set_cs(const RGBColor& c);

    void
    set_cs(float r, float g, float b);

    void
    set_cs(float c);

private:
    float		ks;
    RGBColor 	cs;			/**< Specular color. */
    float		exp; 		/**< specular exponent. */
    Sampler*	sampler;
};


#endif //_GLOSSYSPECULAR_H
