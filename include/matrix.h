#include <vector>

using std::vector;

class Matrix{
    private:
        vector<float> _inner_vec = {};
        vector<vector<float>> _outer_vec = {};
        size_t _prev_inner_vec_size = 0;
    public:
        Matrix(std::initializer_list<std::initializer_list<float>> arg){
            int count = 1;
            for (auto &row: arg){
                _inner_vec = {};
                for (auto elem: row){
                    _inner_vec.push_back(elem);
                }
                if (count == 1)
                    _prev_inner_vec_size = _inner_vec.size();
                if (count > 1){
                    if (_prev_inner_vec_size != _inner_vec.size())
                        throw "Ill-formed matrix!";
                }
                _prev_inner_vec_size = _inner_vec.size();
                _outer_vec.push_back(_inner_vec);
                ++count;
            }
        }
        vector<float>& operator[](const size_t i);
        const vector<float>& operator[](const size_t i) const;
        friend bool operator==(const Matrix &A, const Matrix &B);
};

bool operator!=(const Matrix &A, const Matrix &B);
