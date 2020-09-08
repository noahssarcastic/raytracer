//
// Created by ninig on 4/26/2020.
//

#ifndef _BBOX_H
#define _BBOX_H

#include <Point3D.h>
#include <Ray.h>


class BBox {
public:
    double x0, x1, y0, y1, z0, z1;

    BBox();
    BBox(double x0, double x1, double y0, double y1, double z0, double z1);
    BBox(Point3D p0, Point3D p1);
    BBox(const BBox& bbox);
    ~BBox();

    BBox&
    operator= (const BBox& rhs);

    bool
    hit(const Ray& ray) const;
};


#endif //_BBOX_H
