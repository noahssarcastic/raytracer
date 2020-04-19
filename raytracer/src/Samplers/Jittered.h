//
// Created by ninig on 4/18/2020.
//

#ifndef _JITTERED_H
#define _JITTERED_H

#include "Sampler.h"


class Jittered: public Sampler {
public:
    Jittered();
    explicit Jittered(const int samples);
    Jittered(const int samples, const int sets);
    Jittered(const Jittered& u);

    virtual
    ~Jittered();

    virtual Jittered*
    clone() const;

    Jittered&
    operator= (const Jittered& rhs);

private:
    virtual void
    generate_samples();
};


#endif //_JITTERED_H
