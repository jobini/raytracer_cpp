#include <vector>

using std::vector;

class Matrix{
    private:
        vector<vector<float>> _matrix;
    public:
        Matrix(std::initializer_list<std::initializer_list<float>> arg){
            if (arg.size() == 0)
                throw "Ill-formed matrix!";
            size_t prev_size = arg.begin()->size();
            if (prev_size == 0)
                throw "Ill-formed matrix!";
            for (auto &inner_vec: arg){
                if (inner_vec.size() != prev_size)
                    throw "Ill-formed matrix!";
            }
            _matrix.resize(arg.size(), vector<float>(arg.begin()->size(), 0));

            for (size_t i = 0; i < arg.size(); ++i){
                for (size_t j = 0; j < arg.begin()->size(); ++j){
                    _matrix[i][j] = *((*(arg.begin() + i)).begin() + j);
                }
            }
            shape.push_back(arg.size());
            shape.push_back(arg.begin()->size());
        }
        vector<float>& operator[](const size_t i);
        vector<size_t> shape;
        const vector<float>& operator[](const size_t i) const;
        Matrix mm(const Matrix &A);
};

bool operator==(const Matrix &A, const Matrix &B);
bool operator!=(const Matrix &A, const Matrix &B);
