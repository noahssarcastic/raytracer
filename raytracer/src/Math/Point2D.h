//
// Created by ninig on 4/18/2020.
//

#ifndef _POINT2D_H
#define _POINT2D_H


class Point2D {
public:
    float x, y;

public:
    Point2D();
    Point2D(const float a);
    Point2D(const float _x, const float _y);
    Point2D(const Point2D& p);
    ~Point2D();

    Point2D&
    operator= (const Point2D& rhs);

    Point2D
    operator* (const float a);
};


#endif //_POINT2D_H
