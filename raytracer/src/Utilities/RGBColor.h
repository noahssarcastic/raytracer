//
// Created by ninig on 4/11/2020.
//

#ifndef RAYTRACER_RGBCOLOR_H
#define RAYTRACER_RGBCOLOR_H


/**
 * Class representing a color with RGB channels 0 to 1 inclusive.
 */
class RGBColor {
public:
    float	r, g, b;

    RGBColor();
    explicit RGBColor(float c);
    RGBColor(float _r, float _g, float _b);
    RGBColor(const RGBColor& c);
    ~RGBColor();

    RGBColor&
    operator= (const RGBColor& rhs);

    RGBColor
    operator+ (const RGBColor& c) const;

    RGBColor&
    operator+= (const RGBColor& c);

    RGBColor
    operator* (float a) const;

    RGBColor&
    operator*= (float a);

    RGBColor
    operator/ (float a) const;

    RGBColor&
    operator/= (float a);

    RGBColor
    operator* (const RGBColor& c) const;

    bool
    operator== (const RGBColor& c) const;

    /**
     * Take RGB values to a power piece-wise.
     * @param p Power variable.
     * @return Return new RGBColor.
     */
    RGBColor
    powc(float p) const;

    /**
     * Average the RGB value.
     * @return Return average.
     */
    float
    average() const;
};


#endif //RAYTRACER_RGBCOLOR_H
