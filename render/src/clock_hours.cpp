#include "transformations.h"
#include "canvas.h"
#include "tuple.h"
#include "color.h"
#include "matrix.h"
#include <iostream>

using TupleClass::point;
using MatrixClass::Matrix;
using TransformationsClass::rotation_z;
using TransformationsClass::translation;

int main()
{
    try{
        int width = 801;
        int height = 801;
        int radius = ((3/8.) * width);

        Canvas c(width, height);
        Tuple centre = point(int(c.width/2.), int(c.height/2.), 0);
        Tuple initial_p = point(0, radius, 0);
        Tuple p = point(0, 0, 0);
        Matrix translation_matrix = translation(centre.x, centre.y, 0);

        for(int i = 0; i <= 11; ++i){
            p = translation_matrix.mm(rotation_z(M_PI * i/6)).mm(initial_p);
            c[int(height - p.y)][int(p.x)] = Color(0, 255, 0);
        }
        c.to_ppm("clock_hours.ppm");
    }
    catch(char const* msg){
        std::cout << msg << std::endl;
    }
}