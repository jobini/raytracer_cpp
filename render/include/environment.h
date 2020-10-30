#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "tuple.h"

class Environment
{
    public:
        Environment(const TupleClass::Tuple &grav, const TupleClass::Tuple &win):
                    gravity(grav), wind(win){}
        TupleClass::Tuple gravity;
        TupleClass::Tuple wind;
};

#endif