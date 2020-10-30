#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "tuple.h"

class Projectile
{
    public:
        Projectile(const TupleClass::Tuple &pos, const TupleClass::Tuple &vel):
                               position(pos), velocity(vel){}
        TupleClass::Tuple position;
        TupleClass::Tuple velocity;
};

#endif