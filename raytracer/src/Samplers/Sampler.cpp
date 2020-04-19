//
// Created by ninig on 4/18/2020.
//

#include <algorithm>
#include "Sampler.h"


Sampler::Sampler(): num_samples(1), num_sets(83), count(0), jump(0) {
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const int _samples): num_samples(_samples), num_sets(83), count(0), jump(0) {
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const int _samples, const int sets): num_samples(_samples), num_sets(sets), count(0), jump(0) {
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::Sampler(const Sampler& s): num_samples(s.num_samples), num_sets(s.num_sets), count(s.count), jump(s.jump) {
    samples.reserve(num_samples * num_sets);
    setup_shuffled_indices();
}

Sampler::~Sampler() {}

Sampler&
Sampler::operator= (const Sampler& rhs) {
    if (this == &rhs)
        return *this;
    num_samples 		= rhs.num_samples;
    num_sets			= rhs.num_sets;
    samples				= rhs.samples;
    shuffled_indices	= rhs.shuffled_indices;
    count				= rhs.count;
    jump				= rhs.jump;
    return *this;
}

void
Sampler::setup_shuffled_indices() {
    shuffled_indices.reserve(num_samples * num_sets);
    vector<int> indices;
    for (int j = 0; j < num_samples; j++) {
        indices.push_back(j);
    }
    for (int p = 0; p < num_sets; p++) {
        random_shuffle(indices.begin(), indices.end());
        for (int j = 0; j < num_samples; j++) {
            shuffled_indices.push_back(indices[j]);
        }
    }
}

void
Sampler::shuffle_samples() {}

Point2D
Sampler::sample_unit_square() {
    if (count % num_samples == 0)
        jump = (rand_int() % num_sets) * num_samples;
    return samples[jump + shuffled_indices[jump + count++ % num_samples]];
}

int Sampler::get_num_samples() {
    return num_samples;
}
