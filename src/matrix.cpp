#include "matrix.h"
#include "consts.h"
#include <cmath>

vector<float>& Matrix::operator[](const size_t i){
    if (i >= _matrix.size())
        throw "Out of bounds of matrix!";
    return this->_matrix[i];
}

const vector<float>& Matrix::operator[](const size_t i) const{
    if (i >= _matrix.size())
        throw "Out of bounds of matrix!";
    return this->_matrix[i];
}

bool operator==(const Matrix &A, const Matrix &B){
    if (A.shape[0] != B.shape[0])
        return false;
    if (A.shape[1] != B.shape[1])
        return false;
    for (size_t i = 0; i < A.shape[0]; ++i){
        for (size_t j = 0; j < A.shape[1]; ++j){
            if (std::abs(A[i][j] - B[i][j]) >= EPSILON)
                return false;
        }
    }
    return true;
}

bool operator!=(const Matrix &A, const Matrix &B){
    return !(A == B);
}