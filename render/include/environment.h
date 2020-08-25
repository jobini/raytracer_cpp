#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "tuple.h"

class Environment
{
    public:
        Environment(const Tuple &grav, const Tuple &win):
                    gravity(grav), wind(win){}
        Tuple gravity;
        Tuple wind;
};

#endif