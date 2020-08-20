#ifndef TUPLE_H
#define TUPLE_H

class Tuple
{   
    public:
        Tuple(float x_coord, float y_coord, float z_coord, float w): 
                    x(x_coord), y(y_coord), z(z_coord), w(w) {}
        bool isPoint();
        bool isVector();
        float x;
        float y;
        float z;
        float w;
};
#endif