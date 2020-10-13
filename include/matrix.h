#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "tuple.h"

namespace MatrixClass{
    class Matrix{
        private:
            std::vector<std::vector<float>> _matrix;
        public:
            Matrix(std::vector<std::vector<float>> arg){
                if (arg.size() == 0)
                    throw "Ill-formed matrix!";
                size_t prev_size = arg.begin()->size();
                if (prev_size == 0)
                    throw "Ill-formed matrix!";
                for (const auto &inner_vec: arg){
                    if (inner_vec.size() != prev_size)
                        throw "Ill-formed matrix!";
                }
                _matrix = arg;
            }
            Matrix(std::initializer_list<std::initializer_list<float>> arg) : 
                    Matrix(std::vector<std::vector<float>>(arg.begin(), arg.end())) {};
            Matrix mm(const Matrix &B) const;
            TupleClass::Tuple mm(const TupleClass::Tuple &B) const;
            Matrix submatrix(size_t row_index, size_t col_index) const;
            Matrix transpose() const;
            std::vector<float>& operator[](const size_t i);
            std::vector<size_t> shape() const;
            const std::vector<float>& operator[](const size_t i) const;
            void print() const;
            bool is_invertible() const;
    };

    bool operator==(const Matrix &A, const Matrix &B);
    bool operator!=(const Matrix &A, const Matrix &B);
    float determinant(const Matrix &A);
    float minor(const Matrix &A, size_t row_index, size_t col_index);
    float cofactor(const Matrix &A, size_t row_index, size_t col_index);
    Matrix inverse(const Matrix &A);
}

#endif
