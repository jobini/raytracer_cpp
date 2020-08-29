#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "color.h"

class Canvas
{
    public:
        Canvas(unsigned w, unsigned h): width(w), height(h){
            pixels.resize(height, std::vector<Color>(width, Color(0, 0, 0)));
        };
        unsigned width;
        unsigned height;
        std::vector<std::vector<Color>> pixels;
        std::vector<Color>& operator[](size_t i);
};



#endif