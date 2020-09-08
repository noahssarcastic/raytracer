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
#include <Camera.h>
#include <Light.h>
#include <Ambient.h>
#include "ViewPlane.h"
#include "GeometricObject.h"


/**
 * Raytracer controller class.
 */
using namespace std;

class World {
public:
    ViewPlane                   vp;
    bitmap_image*               image_ptr;
    Camera*                     camera_ptr;
    Tracer*                     tracer_ptr;
    Light*                      ambient_ptr{};
    RGBColor                    background_color;
    vector<GeometricObject*>    objects;            /**< GeometricObjects in the scene. */
    vector<Light*>              lights;

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

    void
    add_light(Light* light_ptr);

    /**
     * Ray-cast method.
     * @param ray Ray to cast.
     * @return Shading data.
     */
    ShadeRec
    hit_objects(const Ray& ray);

//    /**
//     * Used to visualize ray-tracing
//     * @param hres Horizontal resolution.
//     * @param vres Vertical resolution.
//     */
//    void
//    open_window(int hres, int vres);

    /**
     * Clamp RGBColor to in gamut values.
     * @param raw Raw color value.
     * @return Safe color value [0, 1].
     */
    static RGBColor
    clamp(const RGBColor& raw) ;

    /**
     * Replace out-of-gamut RGBColor values with red.
     * @param raw Raw color value.
     * @return Safe color value [0, 1].
     */
    static RGBColor
    clamp_to_color(const RGBColor& raw) ;

    /**
     * Render pixel in image.
     * @param row Viewing coordinates row.
     * @param col Viewing coordinates column.
     * @param raw Raw color value [0, 1]
     */
    void
    display_pixel(int row, int col, const RGBColor& raw) const;

    void
    set_camera(Camera* c);

    void
    set_ambient_light(Ambient* a);
};


#endif //RAYTRACER_WORLD_H
