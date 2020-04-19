//
// Created by ninig on 4/11/2020.
//

#include "GeometricObject.h"
#include "Constants.h"
#include "Material.h"


GeometricObject::GeometricObject(): material_ptr(nullptr) {}

GeometricObject::GeometricObject(const GeometricObject& object): material_ptr(object.material_ptr) {}

GeometricObject::~GeometricObject() {
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
}

GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
    if (this == &rhs)
        return *this;
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();
    return *this;
}

void GeometricObject::set_material(Material *ptr) {
    material_ptr = ptr;
}

Material *GeometricObject::get_material() const {
    return material_ptr;
}

