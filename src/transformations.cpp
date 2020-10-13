#include "matrix.h"

using MatrixClass::Matrix;

namespace TransformationsClass{
    Matrix translation(float x, float y, float z){
        return Matrix({{1, 0, 0, x}, {0, 1, 0, y}, {0, 0, 1, z}, {0, 0, 0, 1}});
    }
}


