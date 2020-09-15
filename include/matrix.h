#include <vector>
#include "tuple.h"

using std::vector;
using TupleClass::Tuple;

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
            shape = {};
            shape.push_back(arg.size());
            shape.push_back(arg.begin()->size());
        }
        Matrix(std::initializer_list<std::initializer_list<float>> arg) : 
                Matrix(vector<vector<float>>(arg.begin(), arg.end())) {};
        Matrix mm(const Matrix &B) const;
        Tuple mm(const Tuple &B) const;
        Matrix transpose() const;
        vector<float>& operator[](const size_t i);
        vector<float> shape;
        const vector<float>& operator[](const size_t i) const;
};

bool operator==(const Matrix &A, const Matrix &B);
bool operator!=(const Matrix &A, const Matrix &B);
