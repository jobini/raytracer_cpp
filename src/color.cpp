#include "color.h"
#include <iostream>

Color operator*(const Color &a, const Color &b){
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}

Color& Color::operator=(const Color &a){
    x = a.red;
    red = a.red;
    y = a.green;
    green = a.green;
    z = a.blue;
    blue = a.blue;
    return *this;
}