//
// Created by ninig on 4/26/2020.
//

#include <Constants.h>
#include "Compound.h"


Compound::Compound (): GeometricObject() {}

Compound::Compound (const Compound& c): GeometricObject(c) {
    copy_objects(c.objects);
}

Compound::~Compound() {
    int num_objects = objects.size();
    for (int j = 0; j < num_objects; j++) {
        delete objects[j];
        objects[j] = nullptr;
    }
    objects.erase(objects.begin(), objects.end());
}

Compound&
Compound::operator= (const Compound& rhs) {
    if (this == &rhs)
        return (*this);
    GeometricObject::operator=(rhs);
    copy_objects(rhs.objects);
    return (*this);
}

Compound*
Compound::clone() const {
    return new Compound(*this);
}

void
Compound::add_object(GeometricObject* object_ptr) {
    objects.push_back(object_ptr);
}

void
Compound::set_material(Material* material_ptr) {
    int num_objects = objects.size();

    for (int j = 0; j < num_objects; j++)
        objects[j]->set_material(material_ptr);
}

void
Compound::delete_objects() {
    int num_objects = objects.size();
    for (int j = 0; j < num_objects; j++) {
        delete objects[j];
        objects[j] = nullptr;
    }
    objects.erase(objects.begin(), objects.end());
}

void
Compound::copy_objects(const vector<GeometricObject*>& rhs_ojects) {
    delete_objects();
    int num_objects = rhs_ojects.size();

    for (int j = 0; j < num_objects; j++)
        objects.push_back(rhs_ojects[j]->clone());
}

bool
Compound::hit(const Ray& ray, double& tmin, ShadeRec& sr) {
    double		t;
    Normal		normal;
    Point3D		local_hit_point;
    bool		hit 		= false;
    tmin 		= K_HUGE_VALUE;
    int 		num_objects	= objects.size();

    for (int j = 0; j < num_objects; j++)
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            hit				= true;
            tmin 			= t;
            material_ptr	= objects[j]->get_material();
            normal			= sr.normal;
            local_hit_point	= sr.local_hit_point;
        }

    if (hit) {
        sr.t				= tmin;
        sr.normal 			= normal;
        sr.local_hit_point 	= local_hit_point;
    }

    return (hit);
}

bool Compound::shadow_hit(const Ray& ray, float& tmin) {
    return false;
}

int Compound::get_num_objects() {
    return objects.size();
}

