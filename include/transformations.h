#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "matrix.h"

namespace TransformationsClass{
    MatrixClass::Matrix translation(float x, float y, float z);
    MatrixClass::Matrix scaling(float x, float y, float z);
    MatrixClass::Matrix rotation_x(float r);
    MatrixClass::Matrix rotation_y(float r);
    MatrixClass::Matrix rotation_z(float r);
    MatrixClass::Matrix shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);
}

#endif