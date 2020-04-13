//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H


class Normal;
class Point3D;

class Vector3D {
public:
    double	x, y, z;

    Vector3D(void);
    Vector3D(double a);
    Vector3D(double _x, double _y, double _z);
    Vector3D(const Vector3D& v);
    Vector3D(const Normal& n);
    Vector3D(const Point3D& p);
    ~Vector3D (void);

    Vector3D&
    operator= (const Vector3D& rhs);

    Vector3D&
    operator= (const Normal& rhs);

    Vector3D&
    operator= (const Point3D& rhs);

    Vector3D
    operator- (void) const;

    Vector3D
    operator* (const double a) const;

    Vector3D
    operator/ (const double a) const;

    Vector3D
    operator+ (const Vector3D& v) const;

    Vector3D&
    operator+= (const Vector3D& v);

    Vector3D
    operator- (const Vector3D& v) const;

    double
    operator* (const Vector3D& b) const;

    Vector3D
    operator^ (const Vector3D& v) const;

    double
    length(void);

    double
    len_squared(void);

    void
    normalize(void);

    Vector3D&
    hat(void);
};


#endif //RAYTRACER_VECTOR3D_H
