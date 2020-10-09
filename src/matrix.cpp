#include "matrix.h"
#include "consts.h"
#include <cmath>
#include <iostream>

using std::vector;

namespace MatrixClass{
    
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
        if (A.shape()[0] != B.shape()[0])
            return false;
        if (A.shape()[1] != B.shape()[1])
            return false;
        for (size_t i = 0; i < A.shape()[0]; ++i){
            for (size_t j = 0; j < A.shape()[1]; ++j){
                if (std::abs(A[i][j] - B[i][j]) >= EPSILON)
                    return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix &A, const Matrix &B){
        return !(A == B);
    }

    vector<size_t> Matrix::shape() const{
        return vector({this->_matrix.size(), this->_matrix[0].size()});
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
        trans.resize(this->shape()[1], vector<float>(this->shape()[0], 0));

        for (size_t i = 0; i < this->shape()[1]; ++i){
            for (size_t j = 0; j < this->shape()[0]; ++j){
                trans[i][j] = this->_matrix[j][i];
            }
        }
        return Matrix(trans);
    }

    Matrix Matrix::mm(const Matrix &B) const{
        if(this->shape()[1] != B.shape()[0])
            throw "Matrix dimensions don't match for multiplication!";
        
        vector<vector<float>> prod;
        prod.resize(this->shape()[0], vector<float>(B.shape()[1], 0));

        for (size_t i = 0; i < this->shape()[0]; ++i){
            for (size_t j = 0; j < B.shape()[1]; ++j){
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

    float determinant(const Matrix &A){
        if (A.shape()[0] != A.shape()[1])
            throw "Not a square matrix!";
        if (A.shape()[0] == 1)
            return A[0][0];
        if (A.shape()[0] == 2)
            return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
        else{
            float det = 0;
            for (size_t j = 0; j < A.shape()[1]; ++j){
                det += A[0][j] * cofactor(A, 0, j);
            }
            return det;
        }
    }

    float minor(const Matrix &A, size_t row_index, size_t col_index){
        return determinant(A.submatrix(row_index, col_index));
    }

    float cofactor(const Matrix &A, size_t row_index, size_t col_index){
        return pow(-1, row_index + col_index) * minor(A, row_index, col_index);
    }

    void Matrix::print() const{
        for (size_t i = 0; i < this->shape()[0]; ++i){
            std::cout << "|";
            for (size_t j = 0; j < this->shape()[1]; ++j){
                if (j != this->shape()[1] - 1)
                    std::cout << this->operator[](i)[j] << " ";
                else
                    std::cout << this->operator[](i)[j];
            }
            std::cout << "|" << std::endl;
        }
    }

    Matrix Matrix::submatrix(size_t row_index, size_t col_index) const{
        if (row_index >= this->shape()[0] || col_index >= this->shape()[1])
            throw "Out of bounds of matrix!";
        Matrix sub(this->_matrix);
        sub._matrix.erase(sub._matrix.begin() + row_index);
        sub = sub.transpose();
        sub._matrix.erase(sub._matrix.begin() + col_index);
        return sub.transpose();
    }
}