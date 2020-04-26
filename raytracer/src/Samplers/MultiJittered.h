//
// Created by ninig on 4/18/2020.
//

#ifndef _MULTIJITTERED_H
#define _MULTIJITTERED_H

#include "Sampler.h"


class MultiJittered: public Sampler {
public:
    MultiJittered();
    explicit MultiJittered(int samples);
    MultiJittered(int samples, int sets);
    MultiJittered(const MultiJittered& mjs);


    ~MultiJittered() override;

    MultiJittered&
    operator= (const MultiJittered& rhs);

    MultiJittered*
    clone() const override;

    void
    shuffle_x_coordinates();

    void
    shuffle_y_coordinates();

private:
    void
    generate_samples() override;
};


#endif //_MULTIJITTERED_H
