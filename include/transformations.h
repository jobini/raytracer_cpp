#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "matrix.h"

namespace TransformationsClass{
    MatrixClass::Matrix translation(float x, float y, float z);
    MatrixClass::Matrix scaling(float x, float y, float z);
    MatrixClass::Matrix rotation_x(float r);
    MatrixClass::Matrix rotation_y(float r);
    MatrixClass::Matrix rotation_z(float r);
}

#endif