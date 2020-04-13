//
// Created by ninig on 4/12/2020.
//

#ifndef RAYTRACER_NORMAL_H
#define RAYTRACER_NORMAL_H


class Normal {
    public:
        double	x, y, z;

        Normal(void);
        Normal(double a);
        Normal(double _x, double _y, double _z);
        Normal(const Normal& n);
        Normal(const Vector3D& v);
        ~Normal(void);

        Normal&
        operator= (const Normal& rhs);

        Normal&
        operator= (const Vector3D& rhs);

        Normal&
        operator= (const Point3D& rhs);

        Normal
        operator- (void) const;

        Normal
        operator+ (const Normal& n) const;

        Normal&
        operator+= (const Normal& n);

        double
        operator* (const Vector3D& v) const;

        Normal
        operator* (const double a) const;

        void
        normalize(void);
};


#endif //RAYTRACER_NORMAL_H
