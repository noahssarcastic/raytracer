//
// Created by ninig on 4/18/2020.
//

#include <cmath>
#include "Jittered.h"


Jittered::Jittered(): Sampler() {}

Jittered::Jittered(const int samples): Sampler(samples) {
    generate_samples();
}

Jittered::Jittered(const int samples, const int sets): Sampler(samples, sets) {
    generate_samples();
}

Jittered::Jittered(const Jittered& u): Sampler(u) {}

Jittered::~Jittered() {}

Jittered*
Jittered::clone() const {
    return new Jittered(*this);
}

Jittered&
Jittered::operator=(const Jittered& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator= (rhs);
    return *this;
}

void
Jittered::generate_samples() {
    int n = (int) sqrt((float)num_samples);
    for (int p = 0; p < num_sets; p++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                Point2D sp((k + rand_float()) / n, (j + rand_float()) / n);
                samples.push_back(sp);
            }
        }
    }
}