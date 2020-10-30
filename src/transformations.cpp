#include "matrix.h"
#include <cmath>

using MatrixClass::Matrix;

namespace TransformationsClass{
    Matrix translation(float x, float y, float z){
        return Matrix({{1, 0, 0, x}, 
                       {0, 1, 0, y},
                       {0, 0, 1, z},
                       {0, 0, 0, 1}});
    }
    Matrix scaling(float x, float y, float z){
        return Matrix({{x, 0, 0, 0},
                       {0, y, 0, 0},
                       {0, 0, z, 0},
                       {0, 0, 0, 1}});
    }
    Matrix rotation_x(float r){
        return Matrix({{1, 0, 0, 0}, 
                       {0, cos(r), -sin(r), 0},
                       {0, sin(r), cos(r), 0},
                       {0, 0, 0, 1}});
    }
    Matrix rotation_y(float r){
        return Matrix({{cos(r), 0, sin(r), 0}, 
                       {0, 1, 0, 0},
                       {-sin(r), 0, cos(r), 0},
                       {0, 0, 0, 1}});
    }
    Matrix rotation_z(float r){
        return Matrix({{cos(r), -sin(r), 0, 0}, 
                       {sin(r), cos(r), 0, 0},
                       {0, 0, 1, 0},
                       {0, 0, 0, 1}});
    }

    Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y){
        return Matrix({{1, x_y, x_z, 0},
                       {y_x, 1, y_z, 0},
                       {z_x, z_y, 1, 0},
                       {0, 0, 0, 1}});
    }
}


