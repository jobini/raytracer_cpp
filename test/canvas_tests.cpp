#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "consts.h"
#include "canvas.h"
#include <string>
#include <fstream>

using std::string;

TEST_CASE("Creating a canvas"){
    GIVEN ("A canvas c with width 10 and height 20 pixels"){
        Canvas c = Canvas(10, 20);

        REQUIRE(c.width == Approx(10).margin(EPSILON));
        REQUIRE(c.height == Approx(20).margin(EPSILON));
        
        for(size_t i = 0; i < c.height; ++i){
            for (size_t j = 0; j < c.width; ++j){
                REQUIRE(c.pixels[i][j] == Color(0, 0, 0));
            }
        }
    }
}

TEST_CASE("Writing pixels to a canvas"){
    GIVEN ("A canvas c with width 10 and height 20 pixels, and the color red"){
        Canvas c = Canvas(10, 20);
        Color red = Color(1, 0, 0);

        c[2][3] = red;
        REQUIRE(c[2][3] == Color(1, 0, 0));
    }
}

TEST_CASE("Constructing the PPM header"){
    GIVEN ("A canvas c with width 5 and height 3 pixels"){
        Canvas c = Canvas(5, 3);
        c.to_ppm("test.ppm");
        std::ifstream file(OUTPUT_DIR + "test.ppm");

        string line;
        string header;
        int line_counter = 0;
        while(std::getline(file, line)){
            header += line.c_str();
            header += "\n";
            ++line_counter;
            if (line_counter == 3)
                break;
        }
        REQUIRE(header == "P3\n5 3\n255\n");
    }
}