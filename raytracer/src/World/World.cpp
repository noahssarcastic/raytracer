//
// Created by ninig on 4/12/2020.
//

#include <algorithm>

#include <Constants.h>
#include <SingleSphere.h>
#include <Vector3D.h>
#include <Point3D.h>
#include "World.h"


World::World(): vp(), background_color(BLACK), sphere(), tracer_ptr(), image_ptr() {}

void
World::build() {
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    background_color = BLACK;
    tracer_ptr = new SingleSphere(this);

    sphere.set_center(Point3D(0.0));
    sphere.set_radius(85.0);
}

World::~World() {
    if (tracer_ptr)
        tracer_ptr = nullptr;
    if (image_ptr)
        image_ptr = nullptr;
}

void
World::render_scene() {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    double x, y;

    bitmap_image image(vp.hres, vp.vres);
    image_ptr = &image;
    image.set_all_channels(background_color.r, background_color.g, background_color.b);
    ray.d = Vector3D(0, 0, -1);

    for (int r = 0; r < vp.vres; r++)
        for (int c = 0; c < vp.vres; c++) {
            x = vp.s * (c - 0.5 * (vp.hres - 1.0));
            y = vp.s * (r - 0.5 * (vp.vres - 1.0));
            ray.o = Point3D(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }
    image.save_image("../../out/output.bmp");
}

void
World::open_window(const int hres, const int vres) {

}

RGBColor
World::clamp(const RGBColor& raw) const  {
    float max_value = std::max(raw.r, std::max(raw.g, raw.b));
    if (max_value > 1.0)
        return (raw / max_value);
    else
        return (raw);
}

RGBColor
World::clamp_to_color(const RGBColor& raw) const {
    RGBColor c(raw);
    if (raw.r > 1.0 || raw.g > 1.0 || raw.b > 1.0)
        c.r = 1.0; c.g = 0.0; c.b = 0.0;
    return c;
}

void
World::display_pixel(const int row, const int col, const RGBColor& raw) const {
    RGBColor mapped;

    if (vp.show_gamut_error)
        mapped = clamp_to_color(raw);
    else
        mapped = clamp(raw);

    if (vp.gamma != 1.0)
        mapped = mapped.powc(vp.inv_gamma);

    int x = col;
    int y = vp.vres - row - 1;
    image_ptr->set_pixel(x, y, static_cast<char>(mapped.r*255), static_cast<char>(mapped.g*255), static_cast<char>(mapped.b*255));
}