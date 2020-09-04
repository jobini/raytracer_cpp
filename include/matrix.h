#include <vector>

using std::vector;

class Matrix{
    private:
        vector<float> _inner_vec;
        vector<vector<float>> _outer_vec;
    public:
        Matrix(std::initializer_list<std::initializer_list<float>> arg){
            for (auto row: arg){
                _inner_vec = {};
                for (auto elem: row){
                    _inner_vec.push_back(elem);
                }
                _outer_vec.push_back(_inner_vec);
            }
        }
        vector<float>& operator[](const unsigned i);
};
