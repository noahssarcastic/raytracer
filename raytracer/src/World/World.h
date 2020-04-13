//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_WORLD_H
#define RAYTRACER_WORLD_H


#include <vector>

#include <RGBColor.h>
#include <Sphere.h>
#include <Tracer.h>
#include <bitmap_image.hpp>
#include "ViewPlane.h"


using namespace std;

class World {
public:
    ViewPlane               vp;
    RGBColor                background_color;
    Tracer*                 tracer_ptr;
    bitmap_image*           image_ptr;
    Sphere 					sphere;
    vector<GeometricObject*> objects;

    World();
    ~World();

    void
    build();

    void
    add_object(GeometricObject* object_ptr);

    ShadeRec
    hit_bare_bones_objects(const Ray& ray);

    void
    render_scene();

    void
    open_window(int hres, int vres);

    RGBColor
    clamp(const RGBColor& raw) const;

    RGBColor
    clamp_to_color(const RGBColor& raw) const;

    void
    display_pixel(int row, int col, const RGBColor& raw) const;
};


#endif //RAYTRACER_WORLD_H
