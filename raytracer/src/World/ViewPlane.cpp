//
// Created by ninig on 4/12/2020.
//

#include <Regular.h>
#include <MultiJittered.h>
#include "ViewPlane.h"


ViewPlane::ViewPlane():
    hres(200),
    vres(200),
    s(1.0),
    gamma(1.0),
    inv_gamma(1.0),
    show_gamut_error(false),
    sampler_ptr(new Regular(1)),
    num_samples(1) {}

ViewPlane::~ViewPlane() {}

void
ViewPlane::set_hres(const int h) {
    hres = h;
}

void
ViewPlane::set_vres(const int v) {
    vres = v;
}

void
ViewPlane::set_pixel_size(const float _s) {
    s = _s;
}

void
ViewPlane::set_gamma(const float g) {
    gamma = g;
    inv_gamma = 1.0 / gamma;
}

void
ViewPlane::set_gamut_display(const bool show) {
    show_gamut_error = show;
}

void
ViewPlane::set_sampler(Sampler *sp) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    num_samples = sp->get_num_samples();
    sampler_ptr = sp;
}

void
ViewPlane::set_samples(const int n) {
    num_samples = n;
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (num_samples > 1)
        sampler_ptr = new MultiJittered(num_samples);
    else
        sampler_ptr = new Regular(1);
}
