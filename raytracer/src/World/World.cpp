//
// Created by ninig on 4/12/2020.
//

#include <Constants.h>
#include <SingleSphere.h>
#include <Vector3D.h>
#include <Point3D.h>
#include <MultipleObjects.h>
#include <Plane.h>
#include <Jittered.h>
#include <Regular.h>
#include <Pinhole.h>
#include "World.h"


World::World(): vp(), background_color(BLACK), tracer_ptr(), image_ptr(), sphere(), d(500), eye(500), camera_ptr() {}

World::~World() {
    if (tracer_ptr)
        tracer_ptr = nullptr;
    if (image_ptr)
        image_ptr = nullptr;
    if (camera_ptr)
        camera_ptr = nullptr;
}

void
World::build() {
    int num_samples = 1; // Use this for all samplers to avoid sampling misalignment.
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_sampler(new Regular(num_samples));
    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    tracer_ptr = new MultipleObjects(this);

    auto* pinhole_ptr = new Pinhole();
    pinhole_ptr->set_eye(300, 400, 500);
    pinhole_ptr->set_lookat(0, 0, -50);
    pinhole_ptr->set_view_distance(400);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    background_color = BLACK;
    auto* sphere_ptr = new Sphere(Point3D(10, -25, 0), 80);
    sphere_ptr->set_color(1, 0, 1);
    add_object(sphere_ptr);
    sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
    sphere_ptr->set_color(1, 1, 0);
    add_object(sphere_ptr);
    auto* plane_ptr = new Plane(Point3D(0, 0, 0), Normal(0, 1, 1));
    plane_ptr->set_color(0.0, 0.3, 0.0);
    add_object(plane_ptr);
}

void
World::add_object(GeometricObject* object_ptr) {
    objects.push_back(object_ptr);
}

ShadeRec
World::hit_bare_bones_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    double tmin = K_HUGE_VALUE;
    int num_objects = objects.size();
    for (int i = 0; i < num_objects; i++)
        if (objects[i]->hit(ray, t, sr) && t < tmin) {
            sr.hit = true;
            tmin = t;
            sr.color = objects[i]->get_color();
        }
    return sr;
}

void
World::render_sampled() {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    Point2D sp;
    Point2D pp;

    bitmap_image image(vp.hres, vp.vres);
    image_ptr = &image;
    image.set_all_channels(
            static_cast<char>(background_color.r * 255),
            static_cast<char>(background_color.g * 255),
            static_cast<char>(background_color.b * 255));

    ray.d = Vector3D(0, 0, -1);
    for (int r = 0; r < vp.vres; r++)
        for (int c = 0; c < vp.vres; c++) {
            pixel_color = BLACK;
            for (int i = 0; i < vp.num_samples; i++) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
                pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
                ray.o = Point3D(pp.x, pp.y, zw);
                pixel_color += tracer_ptr->trace_ray(ray);
            }
            pixel_color /= vp.num_samples;
            display_pixel(r, c, pixel_color);
        }
    image.save_image("../../out/output.bmp");
}

void
World::render_scene() {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    double x, y;

    bitmap_image image(vp.hres, vp.vres);
    image_ptr = &image;
    image.set_all_channels(
            static_cast<char>(background_color.r * 255),
            static_cast<char>(background_color.g * 255),
            static_cast<char>(background_color.b * 255));

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
World::render_perspective() {
    RGBColor pixel_color;
    Ray ray;

    bitmap_image image(vp.hres, vp.vres);
    image_ptr = &image;
    image.set_all_channels(
            static_cast<char>(background_color.r * 255),
            static_cast<char>(background_color.g * 255),
            static_cast<char>(background_color.b * 255));

    ray.o = Point3D(0.0, 0.0, eye);
    for (int r = 0; r < vp.vres; r++)
        for (int c = 0; c < vp.vres; c++) {
            ray.d = Vector3D(
                    vp.s * (c - 0.5 * (vp.hres - 1.0)),
                    vp.s * (r - 0.5 * (vp.vres - 1.0)),
                    -d);
            ray.d.normalize();
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
    if (raw.r > 1.0 || raw.g > 1.0 || raw.b > 1.0) {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }
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
    image_ptr->set_pixel(
            x, y,
            static_cast<char>(mapped.r * 255),
            static_cast<char>(mapped.g * 255),
            static_cast<char>(mapped.b * 255));
}

void World::set_camera(Camera *c) {
    camera_ptr = c;
}
