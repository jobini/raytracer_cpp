#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "tuple.h"

class Projectile
{
    public:
        Projectile(const Tuple &pos, const Tuple &vel):
                               position(pos), velocity(vel){}
        Tuple position;
        Tuple velocity;
};

#endif