//
// Created by ninig on 4/18/2020.
//

#include <cmath>
#include "Regular.h"


Regular::Regular(): Sampler() {}

Regular::Regular(const int num): Sampler(num) {
    generate_samples();
}

Regular::Regular(const Regular& u): Sampler(u) {
    generate_samples();
}

Regular::~Regular() {}

Regular*
Regular::clone() const {
    return new Regular(*this);
}

Regular&
Regular::operator= (const Regular& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator= (rhs);
    return *this;
}

void
Regular::generate_samples() {
    int n = (int) sqrt((float)num_samples);
    for (int i = 0; i < num_sets; i++) {
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                samples.push_back(Point2D((q + 0.5) / n, (p + 0.5) / n));
            }
        }
    }
}