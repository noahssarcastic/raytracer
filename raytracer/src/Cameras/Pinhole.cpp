//
// Created by ninig on 4/18/2020.
//

#include <Constants.h>
#include <ViewPlane.h>
#include <Ray.h>
#include <cmath>
#include "Pinhole.h"


Pinhole::Pinhole(): Camera(), d(500), zoom(1.0) {}

Pinhole::Pinhole(const Pinhole& ph): Camera(ph), d(ph.d), zoom(ph.zoom) {}

Pinhole::~Pinhole() = default;

Pinhole&
Pinhole::operator=(const Pinhole& rhs) {
    if (this == &rhs)
        return *this;
    Camera::operator= (rhs);
    d = rhs.d;
    zoom = rhs.zoom;
    return *this;
}

Camera*
Pinhole::clone() const {
    return new Pinhole(*this);
}

void
Pinhole::set_view_distance(const float vpd) {
    d = vpd;
}

void
Pinhole::set_zoom(const float zoom_factor) {
    zoom = zoom_factor;
}

Vector3D
Pinhole::get_direction(const Point2D& p) const {
    Vector3D dir =  u*p.x + v*p.y - w*d;
    dir.normalize();
    return(dir);
}

void
Pinhole::render_scene(World& w) {
    RGBColor	L;
    ViewPlane	vp(w.vp);
    Ray			ray;
    int 		depth = 0;
    Point2D 	pp;
    int n = (int)sqrt((float)vp.num_samples);

//    w.open_window(vp.hres, vp.vres);
    bitmap_image image(vp.hres, vp.vres);
    image.set_all_channels(
            static_cast<char>(w.background_color.r * 255),
            static_cast<char>(w.background_color.g * 255),
            static_cast<char>(w.background_color.b * 255));
    w.image_ptr = &image;

    vp.pixel_size /= zoom;
    ray.o = eye;
    for (int r = 0; r < vp.vres; r++){
        for (int c = 0; c < vp.hres; c++) {
            L = BLACK;
            for (int p = 0; p < n; p++)	{
                for (int q = 0; q < n; q++) {
                    pp.x = vp.pixel_size * (c - 0.5 * vp.hres + (q + 0.5) / n);
                    pp.y = vp.pixel_size * (r - 0.5 * vp.vres + (p + 0.5) / n);
                    ray.d = get_direction(pp);
                    L += w.tracer_ptr->trace_ray(ray, depth);
                }
            }
            L /= vp.num_samples;
            L *= exposure_time;
            w.display_pixel(r, c, L);
        }
    }

    w.image_ptr->save_image("../../out/output.bmp");
}