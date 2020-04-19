//
// Created by ninig on 4/18/2020.
//

#ifndef _BRDF_H
#define _BRDF_H

#include <Sampler.h>
#include "RGBColor.h"
#include "Vector3D.h"
#include "ShadeRec.h"


/**
 * Represent a Bidirectional Reflectance Distribution Function.
 */
class BRDF {
public:
    BRDF();
    BRDF(const BRDF& b);
    ~BRDF();

    virtual BRDF*
    clone() const = 0;

    /**
     * Computer BRDF.
     * @param sr Shaderec for calculation storage.
     * @param wo Incoming unit Vector3D direction.
     * @param wi Outgoing unit Vector3D direction.
     * @return
     */
    virtual RGBColor
    f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const = 0;

    virtual RGBColor
    sample_f(const ShadeRec& sr, const Vector3D& wi, const Vector3D& wo) const = 0;

    virtual RGBColor
    rho(const ShadeRec& sr, const Vector3D& wo) const = 0;

protected:
    Sampler* sampler_ptr;

    BRDF&
    operator=(const BRDF& rhs);
};


#endif //_BRDF_H
