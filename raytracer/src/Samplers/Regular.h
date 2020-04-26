//
// Created by ninig on 4/18/2020.
//

#ifndef _REGULAR_H
#define _REGULAR_H

#include "Sampler.h"


class Regular: public Sampler {
public:
    Regular(void);
    Regular(const int num);
    Regular(const Regular& u);

    virtual
    ~Regular(void);

    virtual Regular*
    clone(void) const;

    Regular&
    operator= (const Regular& rhs);

    virtual void
    generate_samples(void);
};


#endif //_REGULAR_H
