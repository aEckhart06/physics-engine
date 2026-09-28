#include <vector>

class Vect2 {
    public:
        float x;
        float y;
        Vect2(float x, float y);
        Vect2 add(Vect2 other);
        Vect2 sub(Vect2 other);
        Vect2 scale(float scalar);
        float dot(Vect2 other);
        Vect2 cross2d(float scalar);
};

class Body {
    public:
    Vect2 pos;
    Vect2 vel;
    Vect2 acc;
    int theta = 0;
    float omega;
    
    Body(Vect2 x, Vect2 v, Vect2 a, float w);
    void update_state(float dt);
    void compute_net_force(Vect2 forces[]);
    void compute_net_torque(Vect2 torques[]);
};

class World {
    std::vector<Body> bodies;
    float gravity;
    public:
        World(float gravity, std::vector<Body> bodies);
        void update_state(float dt);
};