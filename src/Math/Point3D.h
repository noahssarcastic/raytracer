//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_POINT3D_H
#define RAYTRACER_POINT3D_H


class Point3D {
    public:
        double x, y, z;

        Point3D();
        Point3D(const double a);
        Point3D(const double a, const double b, const double c);
        Point3D(const Point3D& p);
        ~Point3D();

        Point3D&
        operator= (const Point3D& p);

        Point3D
        operator- (void) const;

        Vector3D
        operator- (const Point3D& p) const;

        Point3D
        operator+ (const Vector3D& v) const;

        Point3D
        operator- (const Vector3D& v) const;

        Point3D
        operator* (const double a) const;

        double
        d_squared(const Point3D& p) const;

        double
        distance(const Point3D& p) const;
};


#endif //RAYTRACER_POINT3D_H
