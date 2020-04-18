//
// Created by ninig on 4/12/2020.
//

#include "ViewPlane.h"


ViewPlane::ViewPlane(void):
    hres(200),
    vres(200),
    s(1.0),
    gamma(1.0),
    inv_gamma(1.0),
    show_gamut_error(false) {}

ViewPlane::~ViewPlane(void) {}

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