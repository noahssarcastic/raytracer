//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_WORLD_H
#define RAYTRACER_WORLD_H


#include <RGBColor.h>
#include <Sphere.h>
#include <Tracer.h>
#include <bitmap_image.hpp>
#include "ViewPlane.h"


class World {
public:
    ViewPlane       vp;
    RGBColor        background_color;
    Sphere          sphere;
    Tracer*         tracer_ptr;
    bitmap_image*   image_ptr;

    World(void);
    ~World(void);

    void
    build(void);

    void
    render_scene();

    void
    open_window(const int hres, const int vres);

    RGBColor
    clamp(const RGBColor& raw) const;

    RGBColor
    clamp_to_color(const RGBColor& raw) const;

    void
    display_pixel(const int row, const int col, const RGBColor& raw) const;
};


#endif //RAYTRACER_WORLD_H
