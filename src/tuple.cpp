#include "tuple.h"
#include "consts.h"
#include <cmath>

namespace TupleClass{
    bool Tuple::isPoint(){
        return (this->w == 1.0);
    }

    bool Tuple::isVector(){
        return (this->w == 0.0);
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

    Tuple cross(const Tuple &a, const Tuple &b){
        return vector(a.y * b.z - b.y * a.z, 
                    b.x * a.z - a.x * b.z, 
                    a.x * b.y - b.x * a.y);
    }

    bool operator==(const Tuple &a, const Tuple &b){
        return (std::abs(a.x - b.x) < EPSILON 
                && std::abs(a.y - b.y) < EPSILON
                && std::abs(a.z - b.z) < EPSILON
                && std::abs(a.w - b.w) < EPSILON);
    }

    Tuple operator+(const Tuple &a, const Tuple &b){
        return Tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    Tuple operator-(const Tuple &a, const Tuple &b){
        return Tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    Tuple operator*(const Tuple &a, const float &k){
        return Tuple(k * a.x, k * a.y, k * a.z, k * a.w);
    }

    Tuple operator/(const Tuple &a, const float &k){
        if (k == 0.0)
            throw "Division by 0 error!";
        return Tuple((1/k) * a.x, (1/k) * a.y, (1/k) * a.z, (1/k) * a.w);
    }

    Tuple operator/=(const Tuple &a, const float &k){
        return a / k;
    }

    Tuple operator*=(const Tuple &a, const float &k){
        return a * k;
    }

    Tuple operator-(const Tuple &a){
        return Tuple(-a.x, -a.y, -a.z, -a.w);
    }

    Tuple operator+=(const Tuple &a, const Tuple &b){
        return a + b;
    }

    Tuple operator-=(const Tuple &a, const Tuple &b){
        return a - b;
    }
}