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

    Vector3D();
    Vector3D(double a);
    Vector3D(double _x, double _y, double _z);
    Vector3D(const Vector3D& v);
    Vector3D(const Normal& n);
    Vector3D(const Point3D& p);
    ~Vector3D ();

    Vector3D&
    operator= (const Vector3D& rhs);

    Vector3D&
    operator= (const Normal& rhs);

    Vector3D&
    operator= (const Point3D& rhs);

    Vector3D
    operator- () const;

    Vector3D
    operator* (double a) const;

    Vector3D
    operator/ (double a) const;

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
    length() const;

    double
    len_squared() const;

    void
    normalize();

    Vector3D&
    hat();
};


#endif //RAYTRACER_VECTOR3D_H
