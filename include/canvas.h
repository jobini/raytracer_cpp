#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include "color.h"

using std::string;

class Canvas
{
    private:
        std::vector<std::vector<Color>> _pixels;
    public:
        Canvas(unsigned w, unsigned h): width(w), height(h){
            _pixels.resize(height, std::vector<Color>(width, Color(0, 0, 0)));
        };
        unsigned width;
        unsigned height;
        std::vector<Color>& operator[](const size_t i);
        string to_ppm(string filename);
};



#endif