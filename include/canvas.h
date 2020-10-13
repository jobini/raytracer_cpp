#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include "color.h"

class Canvas
{
    private:
        std::vector<std::vector<Color>> _pixels;
    public:
        Canvas(size_t w, size_t h): width(w), height(h){
            _pixels.resize(height, std::vector<Color>(width, Color(0, 0, 0)));
        };
        size_t width;
        size_t height;
        std::vector<Color>& operator[](const size_t i);
        std::string to_ppm(std::string filename);
};

#endif