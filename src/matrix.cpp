#include "matrix.h"
#include "consts.h"
#include <cmath>

vector<float>& Matrix::operator[](const size_t i){
    if (i >= _outer_vec.size())
        throw "Out of bounds of matrix!";
    return this->_outer_vec[i];
}

const vector<float>& Matrix::operator[](const size_t i) const{
    if (i >= _outer_vec.size())
        throw "Out of bounds of matrix!";
    return this->_outer_vec[i];
}

bool operator==(const Matrix &A, const Matrix &B){
    if (A._outer_vec.size() != B._outer_vec.size())
        return false;
    if (A._inner_vec.size() != B._inner_vec.size())
        return false;
    for (size_t i = 0; i < A._outer_vec.size(); ++i){
        for (size_t j = 0; j < A._inner_vec.size(); ++j){
            if (std::abs(A[i][j] - B[i][j]) >= EPSILON)
                return false;
        }
    }
    return true;
}

bool operator!=(const Matrix &A, const Matrix &B){
    return !(A == B);
}