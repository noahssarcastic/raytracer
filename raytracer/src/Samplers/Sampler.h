//
// Created by ninig on 4/18/2020.
//

#ifndef _SAMPLER_H
#define _SAMPLER_H

#include <vector>
#include <Point2D.h>
#include <MathUtils.h>
#include <Point3D.h>


using namespace std;

class Sampler {
public:
    Sampler();
    explicit Sampler(int samples);
    Sampler(int samples, int sets);
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

    void
    map_samples_to_unit_disk();

    void
    map_samples_to_hemisphere(float p);

//    void
//    map_samples_to_sphere();

    Point2D
    sample_unit_disk();

    Point3D
    sample_hemisphere();

//    Point3D
//    sample_sphere();

    int
    get_num_samples();

protected:
    int             num_samples;
    int             num_sets;
    vector<Point2D> samples;
    vector<int>     shuffled_indices;
    vector<Point2D>	disk_samples;
    vector<Point3D> hemisphere_samples;
//    vector<Point3D> sphere_samples;
    unsigned long   count;
    int             jump;
};


#endif //_SAMPLER_H
