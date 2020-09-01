#include "canvas.h"
#include "consts.h"
#include <string>
#include <algorithm>
#include <fstream>

using std::string;

std::vector<Color>& Canvas::operator[](const size_t i){
    return this->pixels[i];
}

string Canvas::to_ppm(string filename){
    string ppm = "P3\n" + std::to_string(this->width) + " " + std::to_string(this->height) + "\n255\n";
    string line = "";
    int line_counter = 0;
    for (size_t i = 0; i < this->height; ++i){
        line = "";
        for (size_t j = 0; j < this->width; ++j){
            for (size_t k = 0; k < 3; ++k){
                line += std::to_string(std::min(int((*this)[i][j][k] * 255), 255));
                ++line_counter;
                if (line_counter % 17 == 0)
                {
                    line += "\n";
                    ppm += line;
                    line = "";
                }
                else
                    line += " "; 
            }
        }
        line += "\n";
        ppm += line;
        line_counter = 0;
    }
    ppm += "\n";
    std::ofstream out(OUTPUT_DIR + filename);
    out << ppm;
    out.close();
    return ppm;
}