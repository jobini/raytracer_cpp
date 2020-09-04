#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"
#include <cstddef>

class Color: public Tuple {
    private:
        using Tuple::x;
        using Tuple::y;
        using Tuple::z;
        using Tuple::w;
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