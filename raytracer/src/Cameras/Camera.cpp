//
// Created by ninig on 4/18/2020.
//

#include "Camera.h"


Camera::Camera():
    eye(0, 0, 500),
    lookat(0),
    ra(0),
    u(1, 0, 0), v(0, 1, 0), w(0, 0, 1),
    up(0, 1, 0),
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

Camera::~Camera() = default;

Camera&
Camera::operator=(const Camera& rhs) {
    if (this == &rhs)
        return *this;

    eye	= rhs.eye;
    lookat = rhs.lookat;
    ra = rhs.ra;
    up = rhs.up;
    u = rhs.u;
    v = rhs.v;
    w = rhs.w;
    exposure_time = rhs.exposure_time;

    return *this;
}

void
Camera::set_eye(const Point3D& p) {
    eye = p;
}

void
Camera::set_eye(const float x, const float y, const float z) {
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

void
Camera::set_lookat(const Point3D& p) {
    lookat = p;
}

void
Camera::set_lookat(const float x, const float y, const float z) {
    lookat.x = x;
    lookat.y = y;
    lookat.z = z;
}

void
Camera::set_up_vector(const Vector3D& u) {
    up = u;
}

void
Camera::set_up_vector(const float x, const float y, const float z) {
    up.x = x;
    up.y = y;
    up.z = z;
}

void
Camera::set_roll(const float r) {
    ra = r;
}

void
Camera::set_exposure_time(const float e) {
    exposure_time = e;
}

void
Camera::compute_uvw(void) {
    w = eye - lookat;
    w.normalize();
    u = up ^ w;
    u.normalize();
    v = w ^ u;

    if (this->looking_down()) {
        u = Vector3D(0, 0, 1);
        v = Vector3D(1, 0, 0);
        w = Vector3D(0, 1, 0);
    }

    if (this->looking_up()) {
        u = Vector3D(1, 0, 0);
        v = Vector3D(0, 0, 1);
        w = Vector3D(0, -1, 0);
    }
}

bool
Camera::looking_down() {
    return eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y;
}

bool
Camera::looking_up() {
    return eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y;
}

void
Camera::set_roll_angle(float roll) {

}