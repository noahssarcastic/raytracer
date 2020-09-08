//
// Created by ninig on 4/26/2020.
//

#ifndef _COMPOUND_H
#define _COMPOUND_H

#include <vector>
#include "GeometricObject.h"


using namespace std;

class Compound: public GeometricObject {
public:
    Compound();
    Compound(const Compound& c);
    ~Compound () override;

    Compound&
    operator= (const Compound& c);

    Compound*
    clone() const override;

    void
    set_material(Material* material_ptr) override;

    virtual void
    add_object(GeometricObject* object_ptr);

    int
    get_num_objects();

    bool
    hit(const Ray& ray, double& tmin, ShadeRec& s) override;

    bool
    shadow_hit(const Ray& ray, float& tmin) override;

protected:
    vector<GeometricObject*> objects;

private:
    void
    delete_objects();

    void
    copy_objects(const vector<GeometricObject*>& rhs_objects);
};


#endif //_COMPOUND_H
