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
#include <Ambient.h>
#include <RayCast.h>
#include <PointLight.h>
#include <Matte.h>
#include <Phong.h>
#include "World.h"


World::World(): vp(), image_ptr(), camera_ptr(), tracer_ptr(), ambient_ptr(new Ambient), background_color(BLACK) {}

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
    int num_samples = 9; // Use this for all samplers to avoid sampling misalignment.
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_sampler(new Jittered(num_samples));
    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    tracer_ptr = new RayCast(this);

    auto* pinhole_ptr = new Pinhole();
    pinhole_ptr->set_eye(100, 100, 500);
    pinhole_ptr->set_lookat(0, 0, -50);
    pinhole_ptr->set_view_distance(400);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    background_color = BLACK;

    auto* _ambient_ptr = new Ambient();
    _ambient_ptr->scale_radiance(2.0);
    set_ambient_light(_ambient_ptr);

    auto* pl = new PointLight();
    pl->set_location(100, 50, 100);
    pl->scale_radiance(3.0);
    add_light(pl);

    auto* matte_ptr = new Phong();
    matte_ptr->set_ka(0.25);
    matte_ptr->set_kd(0.6);
    matte_ptr->set_cd(1, 1, 0);
    matte_ptr->set_ks(0.2);
    matte_ptr->set_exp(5);
    matte_ptr->set_cs(1);
    auto* sphere_ptr = new Sphere(Point3D(10, -25, 0), 80);
    sphere_ptr->set_material(matte_ptr);
    add_object(sphere_ptr);
}

void
World::add_object(GeometricObject* object_ptr) {
    objects.push_back(object_ptr);
}

ShadeRec
World::hit_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    Normal normal;
    Point3D local_hit_point;
    double tmin = K_HUGE_VALUE;
    int num_objects = objects.size();
    for (int i = 0; i < num_objects; i++){
        if (objects[i]->hit(ray, t, sr) && t < tmin) {
            sr.hit = true;
            tmin = t;
            sr.material_ptr = objects[i]->get_material();
            sr.hit_point = ray.o + ray.d * t;
            normal = sr.normal;
            local_hit_point = sr.local_hit_point;
        }
    }
    if (sr.hit) {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }
    return sr;
}

//void
//World::open_window(const int hres, const int vres) {
//
//}

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

void World::add_light(Light *light_ptr) {
    lights.push_back(light_ptr);
}

void World::set_ambient_light(Ambient *a) {
    ambient_ptr = a;
}
