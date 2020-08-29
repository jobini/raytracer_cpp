#include "canvas.h"

std::vector<Color>& Canvas::operator[](size_t i){
    return this->pixels[i];
}