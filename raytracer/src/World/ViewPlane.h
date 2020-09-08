//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_VIEWPLANE_H
#define RAYTRACER_VIEWPLANE_H

#include <Sampler.h>


/**
 * Class used to store screen data.
 */
class ViewPlane {
public:
    int         hres;
    int         vres;
    float       pixel_size;
    float       gamma;
    float	    inv_gamma;
    bool        show_gamut_error;
    Sampler*    sampler_ptr;
    int         num_samples;
    int         max_bounces;

    ViewPlane();
    ~ViewPlane();

    void
    set_hres(int h);

    void
    set_vres(int v);

    void
    set_pixel_size(float _s);

    void
    set_gamma(float g);

    /**
     * Show colors out of gamut as red.
     * @param show True if gamut errors shown.
     */
    void
    set_gamut_display(bool show);

    void
    set_sampler(Sampler* sp);

    void
    set_samples(int n);

    void
    set_max_bounces(int b);
};


#endif //RAYTRACER_VIEWPLANE_H
