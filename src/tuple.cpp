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

float magnitude(const Tuple &a){
    return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2));
}

Tuple normalize(const Tuple &a){
    if (a == Tuple(0, 0, 0, 0))
        return a;
    return Tuple(a.x/magnitude(a), 
                 a.y/magnitude(a), 
                 a.z/magnitude(a), 
                 a.w/magnitude(a));
}

float dot(const Tuple &a, const Tuple &b){
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
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

Tuple Tuple::operator*(const float &k){
    return Tuple(k * this->x, k* this->y, k * this->z, k * this->w);
}

Tuple Tuple::operator/(const float &k){
    if (k == 0.0)
        throw "Division by 0 error!";
    return Tuple((1/k) * this->x, (1/k) * this->y, (1/k) * this->z, (1/k) * this->w);
}

Tuple Tuple::operator/=(const float &k){
    return *this / k;
}

Tuple Tuple::operator*=(const float &k){
    return *this * k;
}

Tuple Tuple::operator-(){
    return Tuple(-this->x, -this->y, -this->z, -this->w);
}

Tuple Tuple::operator+=(const Tuple &b){
    return *this + b;
}

Tuple Tuple::operator-=(const Tuple &b){
    return *this - b;
}