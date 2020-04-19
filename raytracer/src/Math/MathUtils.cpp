//
// Created by ninig on 4/18/2020.
//

#include "MathUtils.h"
#include "Constants.h"


int
rand_int() {
    return rand();
}

float
rand_float() {
    return (float)rand_int() * INV_RAND_MAX;
}

float
rand_float(int l, float h) {
    return rand_float() * (h - l) + l;
}

int
rand_int(int l, int h) {
    return (int)(rand_float(0, h - l + 1) + l);
}