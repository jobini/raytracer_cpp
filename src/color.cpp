#include "color.h"
#include <iostream>

Color operator*(const Color &a, const Color &b){
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}

float& Color::operator[](const size_t i){
    if (i == 0)
        return this->red;
    if (i == 1)
        return this->green;
    if (i == 2)
        return this->blue;
    throw "Out of index error!";
}

Color& Color::operator=(const Color &a){
    x = a.red;
    y = a.green;
    z = a.blue;

    red = a.red;
    green = a.green;
    blue = a.blue;
    return *this;
}