#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "consts.h"
#include "canvas.h"
#include <string>
#include <fstream>

using std::string;

TEST_CASE("Creating a canvas"){
    GIVEN("A canvas c with width 10 and height 20 pixels"){
        Canvas c = Canvas(10, 20);

        REQUIRE(c.width == Approx(10).margin(EPSILON));
        REQUIRE(c.height == Approx(20).margin(EPSILON));
        
        for(size_t i = 0; i < c.height; ++i){
            for (size_t j = 0; j < c.width; ++j){
                REQUIRE(c[i][j] == Color(0, 0, 0));
            }
        }
    }
}

TEST_CASE("Writing pixels to a canvas"){
    GIVEN("A canvas c with width 10 and height 20 pixels, and the color red"){
        Canvas c = Canvas(10, 20);
        Color red = Color(1, 0, 0);
        THEN("Write to x = 2 (width), y = 3 (height)"){
            c[3][2] = red;
            REQUIRE(c[3][2] == Color(1, 0, 0));
        }
    }
}

TEST_CASE("Constructing the PPM header"){
    GIVEN("A canvas c with width 5 and height 3 pixels"){
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

TEST_CASE("Constructing the PPM pixel data"){
    GIVEN("A canvas c with width 5 and height 3 pixels, and three colors"){
        Canvas c = Canvas(5, 3);
        Color c1 = Color(1.5, 0, 0);
        Color c2 = Color(0, 0.5, 0);
        Color c3 = Color(-0.5, 0, 1);

        c[0][0] = c1;
        c[1][2] = c2;
        c[2][4] = c3;

        c.to_ppm("test2.ppm");
        std::ifstream file(OUTPUT_DIR + "test2.ppm");

        string line;
        string pixel_data;
        int line_counter = 0;
        while(std::getline(file, line)){
            ++line_counter;
            if (line_counter >= 4)
            {
                if (line_counter >= 7)
                    break;
                pixel_data += line.c_str();
                pixel_data += "\n";
            }
        }
        REQUIRE(pixel_data == "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n");
    }
}

TEST_CASE("Splitting long lines in PPM files"){
    GIVEN("A canvas c with width 10 and height 2 pixels"){
        Canvas c = Canvas(10, 2);
        WHEN("Every pixel of c is set to Color(1, 0.8, 0.6) and PPM file is generated"){
            for (size_t i = 0; i < c.height; ++i){
                for (size_t j = 0; j < c.width; ++j){
                    c[i][j] = Color(1, 0.8, 0.6);
                }
            }
            c.to_ppm("test3.ppm");
        }
        std::ifstream file(OUTPUT_DIR + "test3.ppm");

        string line;
        string pixel_data;
        int line_counter = 0;
        while(std::getline(file, line)){
            ++line_counter;
            if (line_counter >= 4)
            {
                if (line_counter >= 8)
                    break;
                pixel_data += line.c_str();
                pixel_data += "\n";
            }
        }
        REQUIRE(pixel_data == "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n");
    }
}

TEST_CASE("PPM files are terminated by a new line"){
    GIVEN("A canvas c with width 5 and height 3 pixels"){
        Canvas c = Canvas(5, 3);
        WHEN("PPM is generated"){
            c.to_ppm("test4.ppm");
        }
        std::ifstream file(OUTPUT_DIR + "test4.ppm");

        string line;
        string last_line;
        while(std::getline(file, line)){}
        last_line = line + "\n";
        REQUIRE(last_line == "\n");
    }
}