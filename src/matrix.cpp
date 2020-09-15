#include "matrix.h"
#include "consts.h"
#include <cmath>

using std::vector;

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

float vector_dot(const vector<float> &x, const vector<float> &y){
    float res = 0;
    if (x.size() != y.size())
        throw "Vector dimensions don't match for dot product!";
    for(size_t i = 0; i < x.size(); ++i){
        res += (x[i] * y[i]);
    }
    return res;
}

Matrix Matrix::transpose() const{
    vector<vector<float>> trans;
    trans.resize(this->shape[1], vector<float>(this->shape[0], 0));

    for (size_t i = 0; i < this->shape[1]; ++i){
        for (size_t j = 0; j < this->shape[0]; ++j){
            trans[i][j] = this->_matrix[j][i];
        }
    }
    return Matrix(trans);
}

Matrix Matrix::mm(const Matrix &B) const{
    if(this->shape[1] != B.shape[0])
        throw "Matrix dimensions don't match for multiplication!";
    
    vector<vector<float>> prod;
    prod.resize(this->shape[0], vector<float>(B.shape[1], 0));

    for (size_t i = 0; i < this->shape[0]; ++i){
        for (size_t j = 0; j < B.shape[1]; ++j){
            prod[i][j] = vector_dot(this->_matrix[i], B.transpose()[j]);
        }
    }
    return Matrix(prod);
}

Tuple Matrix::mm(const Tuple &t) const{
    const Matrix B = {{t.x}, {t.y}, {t.z}, {t.w}};
    const Matrix C = this->mm(B);
    return Tuple(C[0][0], C[1][0], C[2][0], C[3][0]);
}