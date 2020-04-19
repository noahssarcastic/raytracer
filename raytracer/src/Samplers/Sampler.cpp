//
// Created by ninig on 4/18/2020.
//

#include <algorithm>
#include <Constants.h>
#include <cmath>
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

int
Sampler::get_num_samples() {
    return num_samples;
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

void
Sampler::map_samples_to_unit_disk() {
    int size = samples.size();
    float r, phi;
    Point2D sp;
    disk_samples.reserve(size);
    for (int j = 0; j < size; j++) {
        sp.x = 2.0 * samples[j].x - 1.0;
        sp.y = 2.0 * samples[j].y - 1.0;
        if (sp.x > -sp.y) {
            if (sp.x > sp.y) {              // sector 1
                r = sp.x;
                phi = sp.y / sp.x;
            }
            else {                          // sector 2
                r = sp.y;
                phi = 2 - sp.x / sp.y;
            }
        }
        else {
            if (sp.x < sp.y) {              // sector 3
                r = -sp.x;
                phi = 4 + sp.y / sp.x;
            }
            else {                          // sector 4
                r = -sp.y;
                if (sp.y != 0.0)
                    phi = 6 - sp.x / sp.y;
                else
                    phi  = 0.0;
            }
        }
        phi *= PI / 4.0;
        disk_samples[j].x = r * cos(phi);
        disk_samples[j].y = r * sin(phi);
    }
    samples.erase(samples.begin(), samples.end());
}

void
Sampler::map_samples_to_hemisphere(const float e) {
    int size = samples.size();
    hemisphere_samples.reserve(num_samples * num_sets);
    for (int j = 0; j < size; j++) {
        float cos_phi = cos(2.0 * PI * samples[j].x);
        float sin_phi = sin(2.0 * PI * samples[j].x);
        float cos_theta = pow((1.0 - samples[j].y), 1.0 / (e + 1.0));
        float sin_theta = sqrt (1.0 - cos_theta * cos_theta);
        float pu = sin_theta * cos_phi;
        float pv = sin_theta * sin_phi;
        float pw = cos_theta;
        hemisphere_samples.push_back(Point3D(pu, pv, pw));
    }
}

//void
//Sampler::map_samples_to_sphere() {}

Point2D
Sampler::sample_unit_disk() {
    if (count % num_samples == 0)
        jump = (rand_int() % num_sets) * num_samples;
    return (disk_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

Point3D
Sampler::sample_hemisphere() {
    if (count % num_samples == 0)
        jump = (rand_int() % num_sets) * num_samples;
    return (hemisphere_samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

//Point3D
//Sampler::sample_sphere() {}
