//
// Created by ninig on 4/18/2020.
//

#ifndef _PURERANDOM_H
#define _PURERANDOM_H

#include "Sampler.h"


class PureRandom: public Sampler {
public:
    PureRandom();
    explicit PureRandom(int num);
    PureRandom(const PureRandom& r);


    ~PureRandom() override;

    PureRandom*
    clone() const override;

    PureRandom&
    operator=(const PureRandom& rhs);

private:
    void
    generate_samples() override;
};


#endif //_PURERANDOM_H
