//
// Created by ninig on 4/18/2020.
//

#ifndef _NROOKS_H
#define _NROOKS_H

#include "Sampler.h"

class NRooks: public Sampler {
public:
    NRooks();
    explicit NRooks(int samples);
    NRooks(int samples, int sets);
    NRooks(const NRooks& nr);


    ~NRooks() override;

    NRooks&
    operator= (const NRooks& rhs);

    NRooks*
    clone() const override;

    void
    shuffle_x_coordinates();

    void
    shuffle_y_coordinates();

private:
    void
    generate_samples() override;
};


#endif //_NROOKS_H
