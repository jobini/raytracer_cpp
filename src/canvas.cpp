#include "canvas.h"
#include "consts.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <cmath>

using std::string;

std::vector<Color>& Canvas::operator[](const size_t i){
    if (i >= height)
        throw "Out of bounds of canvas!";
    return this->_pixels[i];
}

int clamp(float val){
    if (val > 255)
        return 255;
    if (val < 0)
        return 0;
    return int(val);
}

string Canvas::to_ppm(string filename){
    string ppm = "P3\n" + std::to_string(this->width) 
                 + " " + std::to_string(this->height) + "\n255\n";
    string line = "";
    size_t future_line_size = 0;
    for (size_t i = 0; i < this->height; ++i){
        line = "";

        for (size_t j = 0; j < this->width; ++j){
            for (size_t k = 0; k < 3; ++k){
                if (line.size() == 0){
                    future_line_size = line.size() 
                    + (std::to_string(clamp(std::ceil((*this)[i][j][k] * 255)))).size();
                }
                else
                    future_line_size = line.size() 
                                       + (" " + std::to_string(clamp(std::ceil((*this)[i][j][k] * 255)))).size();
                
                if (future_line_size <= 70){
                    if (line.size() == 0)
                        line += std::to_string(clamp(std::ceil((*this)[i][j][k] * 255)));
                    else
                        line += " " + std::to_string(clamp(std::ceil((*this)[i][j][k] * 255)));
                }
                else
                {
                    line += "\n";
                    ppm += line;
                    line = std::to_string(clamp(std::ceil((*this)[i][j][k] * 255)));
                    future_line_size = 0;
                }
            }
        }
        line += "\n";
        ppm += line;
        future_line_size = 0;
    }
    std::ofstream out(OUTPUT_DIR + filename);
    out << ppm;
    out.close();
    return ppm;
}