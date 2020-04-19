//
// Created by ninig on 4/18/2020.
//

#include "Camera.h"


Camera::Camera():
    eye(0, 0, 500),
    lookat(0),
    ra(0),
    up(0, 1, 0),
    u(1, 0, 0), v(0, 1, 0), w(0, 0, 1),
    exposure_time(1.0)
    {}

Camera::Camera(const Camera& c):
    eye(c.eye),
    lookat(c.lookat),
    ra(c.ra),
    up(c.up),
    u(c.u), v(c.v), w(c.w),
    exposure_time(c.exposure_time)
    {}

virtual
Camera::~Camera() {}

Camera&
Camera::operator=(const Camera& camera) {

}

virtual void
Camera::render_scene(const World& w) = 0;

void
Camera::set_eye(const Point3D& p);

void
Camera::set_eye(const float x, const float y, const float z);

void
Camera::set_lookat(const Point3D& p);

void
Camera::set_lookat(const float x, const float y, const float z);

void
Camera::set_up_vector(const Vector3D& u);

void
Camera::set_up_vector(const float x, const float y, const float z);

void
Camera::set_roll(const float ra);

void
Camera::set_exposure_time(const float exposure);

void
Camera::compute_uvw(void);