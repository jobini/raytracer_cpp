#ifndef TUPLE_H
#define TUPLE_H

namespace TupleClass{
    class Tuple
    {   
        public:
            Tuple(float x_coord, float y_coord, float z_coord, float w): 
                        x(x_coord), y(y_coord), z(z_coord), w(w) {}
            bool isPoint();
            bool isVector();
            float x;
            float y;
            float z;
            float w;
    };

    Tuple operator+(const Tuple &a, const Tuple &b);
    Tuple operator-(const Tuple &a, const Tuple &b);
    Tuple operator-(const Tuple &a);
    Tuple operator*(const Tuple &a, const float &k);
    Tuple operator/(const Tuple &a, const float &k);
    Tuple operator*=(const Tuple &a, const float &k);
    Tuple operator/=(const Tuple &a, const float &k);
    Tuple operator+=(const Tuple &a, const Tuple &b);
    Tuple operator-=(const Tuple &a, const Tuple &b);
    bool operator==(const Tuple &a, const Tuple &b);
    Tuple point(float x, float y, float z);
    Tuple vector(float x, float y, float z);
    float dot(const Tuple &a, const Tuple &b);
    Tuple cross(const Tuple &a, const Tuple &b);
    float magnitude(const Tuple &a);
    Tuple normalize(const Tuple &a);
}

#endif