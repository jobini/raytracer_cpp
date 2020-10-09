#include <vector>
#include "tuple.h"

using std::vector;
using TupleClass::Tuple;

namespace MatrixClass{
    class Matrix{
        private:
            vector<vector<float>> _matrix;
        public:
            Matrix(vector<vector<float>> arg){
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
                    Matrix(vector<vector<float>>(arg.begin(), arg.end())) {};
            Matrix mm(const Matrix &B) const;
            Tuple mm(const Tuple &B) const;
            Matrix submatrix(size_t row_index, size_t col_index) const;
            Matrix transpose() const;
            vector<float>& operator[](const size_t i);
            vector<size_t> shape() const;
            const vector<float>& operator[](const size_t i) const;
            void print() const;
            bool is_invertible() const;
    };

    bool operator==(const Matrix &A, const Matrix &B);
    bool operator!=(const Matrix &A, const Matrix &B);
    float determinant(const Matrix &A);
    float minor(const Matrix &A, size_t row_index, size_t col_index);
    float cofactor(const Matrix &A, size_t row_index, size_t col_index);
}
