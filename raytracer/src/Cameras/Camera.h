//
// Created by ninig on 4/18/2020.
//

#ifndef _CAMERA_H
#define _CAMERA_H


#include <Point3D.h>

class World;

class Camera {
public:
    Camera();
    Camera(const Camera& c);

    virtual
    ~Camera();

    virtual Camera*
    clone() const = 0;

    virtual void
    render_scene(World& w) = 0;

    void
    set_eye(const Point3D& p);

    void
    set_eye(float x, float y, float z);

    void
    set_lookat(const Point3D& p);

    void
    set_lookat(float x, float y, float z);

    void
    set_up_vector(const Vector3D& u);

    void
    set_up_vector(float x, float y, float z);

    void
    set_roll(float r);

    void
    set_exposure_time(float e);

    void
    compute_uvw();

    bool
    looking_up();

    bool
    looking_down();

    void
    set_roll_angle(float roll);

protected:
    Point3D			eye;
    Point3D			lookat;
    float			ra;
    Vector3D		u, v, w;
    Vector3D		up;
    float			exposure_time;

    Camera&
    operator= (const Camera& rhs);
};


#endif //_CAMERA_H
