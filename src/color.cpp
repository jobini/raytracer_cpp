#include "color.h"

Color operator*(const Color &a, const Color &b){
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}