#include "tuple.h"

bool Tuple::isPoint(){
    if (this->w == 1.0)
        return true;
    return false;
}

bool Tuple::isVector(){
    if (this->w == 0.0)
        return true;
    return false;
}

Tuple point(float x, float y, float z){
    return Tuple(x, y, z, 1.0);
}

Tuple vector(float x, float y, float z){
    return Tuple(x, y, z, 0.0);
}

