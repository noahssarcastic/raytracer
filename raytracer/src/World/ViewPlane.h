//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_VIEWPLANE_H
#define RAYTRACER_VIEWPLANE_H


class ViewPlane {
public:
    int     hres;
    int     vres;
    float   s;
    float   gamma;
    float	inv_gamma;
    bool    show_gamut_error;

    ViewPlane(void);
    ~ViewPlane(void);

    void
    set_hres(const int h);

    void
    set_vres(const int v);

    void
    set_pixel_size(const float _s);

    void
    set_gamma(const float g);

    void
    set_gamut_display(const bool show);
};


#endif //RAYTRACER_VIEWPLANE_H
