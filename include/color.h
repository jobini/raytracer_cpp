#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

class Color: private Tuple {
    public:
        Color(float r, float g, float b)
            : Tuple(r, g, b, 0)
            , red(x), green(y), blue(z) 
            {};
        float red;
        float green;
        float blue;
};

#endif