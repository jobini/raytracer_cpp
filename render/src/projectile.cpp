#include <iostream>
#include "tuple.h"
#include "projectile.h"
#include "environment.h"
#include "canvas.h"
#include "color.h"

using TupleClass::point;
using TupleClass::vector;

Projectile tick(const Projectile &proj, const Environment &env){
    Tuple new_position = proj.position + proj.velocity;
    Tuple new_velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(new_position, new_velocity);
}

int main()
{
    try{
        Projectile p = Projectile(point(0, 1, 0), normalize(vector(1, 1.8, 0)) * 11.25);
        Environment e = Environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));

        int width = 900;
        int height = 550;

        Canvas c(width, height);

        while((p.position.y >= 0 && p.position.y <= height) && (p.position.x >= 0 && p.position.x <= width))
        {
            c[int(height - p.position.y)][int(p.position.x)] = Color((rand() % 256)/255., (rand() % 256)/255., (rand() % 256)/255.);
            p = tick(p, e);
        }
        c.to_ppm("projectile.ppm");
    }
    catch(char const *msg){
        std::cout << msg << std::endl;
    }
}