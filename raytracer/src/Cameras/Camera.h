//
// Created by ninig on 4/18/2020.
//

#ifndef _CAMERA_H
#define _CAMERA_H


class Camera {
public:
    Camera();
    Camera(const Camera& c);

    virtual
    ~Camera();

    virtual Camera*
    clone() const = 0;

    virtual void
    render_scene(const World& w) = 0;

    void
    set_eye(const Point3D& p);

    void
    set_eye(const float x, const float y, const float z);

    void
    set_lookat(const Point3D& p);

    void
    set_lookat(const float x, const float y, const float z);

    void
    set_up_vector(const Vector3D& u);

    void
    set_up_vector(const float x, const float y, const float z);

    void
    set_roll(const float ra);

    void
    set_exposure_time(const float exposure);

    void
    compute_uvw(void);

protected:
    Point3D			eye;
    Point3D			lookat;
    float			ra;
    Vector3D		u, v, w;
    Vector3D		up;
    float			exposure_time;

    Camera&
    operator= (const Camera& camera);
};


#endif //_CAMERA_H
