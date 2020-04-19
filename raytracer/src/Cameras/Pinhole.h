//
// Created by ninig on 4/18/2020.
//

#ifndef _PINHOLE_H
#define _PINHOLE_H

#include <Point2D.h>
#include "World.h"


class Pinhole: public Camera {
public:
    Pinhole();
    Pinhole(const Pinhole& ph);
    ~Pinhole() override;

    Pinhole&
    operator= (const Pinhole& rhs);

    Camera*
    clone() const override;

    void
    set_view_distance(float vpd);

    void
    set_zoom(float zoom_factor);

    Vector3D
    get_direction(const Point2D& p) const;

    void
    render_scene(World& w) override;

private:
    float	d;		/**< ViewPlane distance. */
    float	zoom;	/**< Zoom factor. */
};


#endif //_PINHOLE_H
