//
// Created by ninig on 4/18/2020.
//

#include <cmath>
#include "MultiJittered.h"


MultiJittered::MultiJittered(): Sampler() {}

MultiJittered::MultiJittered(const int samples): Sampler(samples) {
    generate_samples();
}

MultiJittered::MultiJittered(const int samples, const int sets): Sampler(samples, sets) {
    generate_samples();
}

MultiJittered::MultiJittered(const MultiJittered& mjs): Sampler(mjs) {
    generate_samples();
}

MultiJittered::~MultiJittered() = default;

MultiJittered&
MultiJittered::operator=(const MultiJittered& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

MultiJittered*
MultiJittered::clone() const {
    return new MultiJittered(*this);
}

void
MultiJittered::generate_samples() {
    int n = (int)sqrt((float)num_samples);
    float subcell_width = 1.0 / ((float) num_samples);
    Point2D fill_point;
    for (int j = 0; j < num_samples * num_sets; j++) {
        samples.push_back(fill_point);
    }

    for (int p = 0; p < num_sets; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + rand_float(0, subcell_width);
                samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + rand_float(0, subcell_width);
            }
        }
    }
    this->shuffle_x_coordinates();
    this->shuffle_y_coordinates();
}

void
MultiJittered::shuffle_x_coordinates() {
    int n = (int)sqrt((float)num_samples);
    for (int p = 0; p < num_sets; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = rand_int(j, n - 1);
                float t = samples[i * n + j + p * num_samples].x;
                samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
                samples[i * n + k + p * num_samples].x = t;
            }
        }
    }
}

void
MultiJittered::shuffle_y_coordinates() {
    int n = (int)sqrt((float)num_samples);
    for (int p = 0; p < num_sets; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = rand_int(j, n - 1);
                float t = samples[j * n + i + p * num_samples].y;
                samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
                samples[k * n + i + p * num_samples].y = t;
            }
        }
    }
}