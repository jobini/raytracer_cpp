#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"
#include <cstddef>

using TupleClass::Tuple;

class Color: public Tuple {
    private:
        using TupleClass::Tuple::x;
        using TupleClass::Tuple::y;
        using TupleClass::Tuple::z;
        using TupleClass::Tuple::w;
    public:
        Color(float r, float g, float b)
            : Tuple(r, g, b, 0)
            , red(x), green(y), blue(z) 
            {};
        float red;
        float green;
        float blue;
        Color& operator=(const Color &a);
        float& operator[](const size_t i);
};

Color operator*(const Color &a, const Color &b);

#endif