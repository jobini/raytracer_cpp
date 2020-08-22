#include "tuple.h"
#include "consts.h"
#include <cmath>

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

bool operator==(const Tuple &a, const Tuple &b){
    return (std::abs(a.x - b.x) < EPSILON 
            && std::abs(a.y - b.y) < EPSILON
            && std::abs(a.z - b.z) < EPSILON
            && std::abs(a.w - b.w) < EPSILON);
}

Tuple Tuple::operator+(const Tuple &b){
    return Tuple(this->x + b.x, this->y + b.y, this->z + b.z, this->w + b.w);
}

Tuple Tuple::operator-(const Tuple &b){
    return Tuple(this->x - b.x, this->y - b.y, this->z - b.z, this->w - b.w);
}

Tuple Tuple::operator+=(const Tuple &b){
    return *this + b;
}

Tuple Tuple::operator-=(const Tuple &b){
    return *this - b;
}