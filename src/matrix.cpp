#include "matrix.h"
#include <iostream>

vector<float>& Matrix::operator[](const unsigned i){
    if (i >= _outer_vec.size())
        throw "Out of bounds of matrix!";
    return this->_outer_vec[i];
}