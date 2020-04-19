//
// Created by ninig on 4/18/2020.
//

#ifndef _SAMPLER_H
#define _SAMPLER_H

#include <vector>
#include <Point2D.h>
#include <MathUtils.h>


using namespace std;

class Sampler {
public:
    Sampler();
    Sampler(const int samples);
    Sampler(const int samples, const int sets);
    Sampler(const Sampler& s);

    virtual
    ~Sampler();

    Sampler&
    operator= (const Sampler& rhs);

    virtual Sampler*
    clone() const = 0;

    virtual void
    generate_samples() = 0;

    void
    setup_shuffled_indices();

    void
    shuffle_samples();

    Point2D
    sample_unit_square();

    int
    get_num_samples();

protected:
    int num_samples;
    int num_sets;
    vector<Point2D> samples;
    vector<int> shuffled_indices;
    unsigned long count;
    int jump;
};


#endif //_SAMPLER_H
