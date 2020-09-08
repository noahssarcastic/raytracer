//
// Created by ninig on 4/26/2020.
//

#ifndef _GRID_H
#define _GRID_H

#include <BBox.h>
#include "Compound.h"


class Grid: public Compound {
public:
    Grid();
    ~Grid() override;

    Grid&
    operator= (const Grid& rhs);

    Grid*
    clone() const override;

    virtual BBox
    get_bounding_box();

    void
    setup_cells();

    bool
    hit(const Ray& ray, double& tmin, ShadeRec& sr) override;

    bool
    shadow_hit(const Ray& ray, float& tmin) override;

private:
    std::vector<GeometricObject*> cells;
    BBox bbox;
    int nx, ny, nz;                         /**< Number of cells in x, y, z direction respectively. */

    Point3D
    min_coordinates();

    Point3D
    max_coordinates();
};


#endif //_GRID_H
