//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_RGBCOLOR_H
#define RAYTRACER_RGBCOLOR_H


class RGBColor {
public:
    float	r, g, b;

    RGBColor(void);
    RGBColor(float c);
    RGBColor(float _r, float _g, float _b);
    RGBColor(const RGBColor& c);
    ~RGBColor(void);

    RGBColor&
    operator= (const RGBColor& rhs);

    RGBColor
    operator+ (const RGBColor& c) const;

    RGBColor&
    operator+= (const RGBColor& c);

    RGBColor
    operator* (const float a) const;

    RGBColor&
    operator*= (const float a);

    RGBColor
    operator/ (const float a) const;

    RGBColor&
    operator/= (const float a);

    RGBColor
    operator* (const RGBColor& c) const;

    bool
    operator== (const RGBColor& c) const;

    RGBColor
    powc(float p) const;

    float
    average(void) const;
};


#endif //RAYTRACER_RGBCOLOR_H
