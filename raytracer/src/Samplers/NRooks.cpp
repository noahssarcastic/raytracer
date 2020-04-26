//
// Created by ninig on 4/18/2020.
//

#include "NRooks.h"


NRooks::NRooks(): Sampler() {}

NRooks::NRooks(const int samples): Sampler(samples) {
    generate_samples();
}

NRooks::NRooks(const int samples, const int sets): Sampler(samples, sets) {
    generate_samples();
}

NRooks::NRooks(const NRooks& nr): Sampler(nr) {
    generate_samples();
}

NRooks::~NRooks() {}

NRooks&
NRooks::operator=(const NRooks& rhs) {
    if (this == &rhs)
        return *this;
    Sampler::operator=(rhs);
    return *this;
}

NRooks*
NRooks::clone() const {
    return new NRooks(*this);
}

void
NRooks::generate_samples() {
    for (int p = 0; p < num_sets; p++)
        for (int j = 0; j < num_samples; j++) {
            Point2D sp((j + rand_float()) / num_samples, (j + rand_float()) / num_samples);
            samples.push_back(sp);
        }

    shuffle_x_coordinates();
    shuffle_y_coordinates();
}

void
NRooks::shuffle_x_coordinates() {
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i <  num_samples - 1; i++) {
            int target = rand_int() % num_samples + p * num_samples;
            float temp = samples[i + p * num_samples + 1].x;
            samples[i + p * num_samples + 1].x = samples[target].x;
            samples[target].x = temp;
        }
}

void
NRooks::shuffle_y_coordinates() {
    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i <  num_samples - 1; i++) {
            int target = rand_int() % num_samples + p * num_samples;
            float temp = samples[i + p * num_samples + 1].y;
            samples[i + p * num_samples + 1].y = samples[target].y;
            samples[target].y = temp;
        }
}