#include <iostream>
#include "tuple.h"
#include "projectile.h"
#include "environment.h"

using std::cout;
using std::endl;

Projectile tick(const Projectile &proj, const Environment &env){
    Tuple new_position = proj.position + proj.velocity;
    Tuple new_velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(new_position, new_velocity);
}

int main()
{
    Projectile p = Projectile(point(0, 1, 0), normalize(vector(1, 1, 0)));
    Environment e = Environment(vector(0, -0.1, 0), vector(-0.01, 0, 0));

    int tick_count = 0;
    while(p.position.y >= 0)
    {
        cout << "Current position: (" + std::to_string(p.position.x) + ", " + 
                                        std::to_string(p.position.y) + ", " + 
                                        std::to_string(p.position.z) + ", " + 
                                        std::to_string(p.position.w) + ")" << endl;
        p = tick(p, e);
        tick_count += 1;
    }
    cout << "Ticks: " << tick_count << endl;
}