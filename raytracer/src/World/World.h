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


/**
 * Raytracer controller class.
 */
using namespace std;

class World {
public:
    ViewPlane                   vp;
    RGBColor                    background_color;
    Tracer*                     tracer_ptr;
    bitmap_image*               image_ptr;
    Sphere 					    sphere;             /**< Sphere used in SingleSphere tracer. */
    vector<GeometricObject*>    objects;            /**< GeometricObjects in the scene. */
    float                       d;
    double                      eye;

    World();
    ~World();

    void
    build();

    /**
     * Add GeometricObject to the scene.
     * @param object_ptr Object to add.
     */
    void
    add_object(GeometricObject* object_ptr);

    /**
     * Rudimentary ray-cast method.
     * @param ray Ray to cast.
     * @return Shading data.
     */
    ShadeRec
    hit_bare_bones_objects(const Ray& ray);

    /**
     *
     */
    void
    render_scene();

    /**
     *
     */
    void
    render_perspective();

    /**
     * Used to visualize ray-tracing
     * @param hres Horizontal resolution.
     * @param vres Vertical resolution.
     */
    void
    open_window(int hres, int vres);

    /**
     * Clamp RGBColor to in gamut values.
     * @param raw Raw color value.
     * @return Safe color value [0, 1].
     */
    RGBColor
    clamp(const RGBColor& raw) const;

    /**
     * Replace out-of-gamut RGBColor values with red.
     * @param raw Raw color value.
     * @return Safe color value [0, 1].
     */
    RGBColor
    clamp_to_color(const RGBColor& raw) const;

    /**
     * Render pixel in image.
     * @param row Viewing coordinates row.
     * @param col Viewing coordinates column.
     * @param raw Raw color value [0, 1]
     */
    void
    display_pixel(int row, int col, const RGBColor& raw) const;

    void render_sampled();
};


#endif //RAYTRACER_WORLD_H
