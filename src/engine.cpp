#include "../include/engine.h"
#include <vector>


// VECTOR CLASS
Vect2::Vect2(float x, float y) {
    this->x = x;
    this->y = y;
};

Vect2 Vect2::add(Vect2 other){
    return Vect2(x + other.x, y + other.y);
};
Vect2 Vect2::sub(Vect2 other){
    return Vect2(x - other.x, y - other.y);
};
Vect2 Vect2::scale(float scalar){
    return Vect2(x * scalar, y * scalar);
};
float Vect2::dot(Vect2 other){
    return x * other.x + y * other.y;
};
Vect2 Vect2::cross2d(float scalar){
    return Vect2(-y * scalar, x * scalar);
};


// RIGID BODY CLASS
Body::Body(Vect2 x, Vect2 v, Vect2 a, float w)
    : pos(x), vel(v), acc(a), omega(w) {}

void Body::update_state(float dt){
    vel.x += acc.x * dt;
    vel.y += acc.y * dt;
    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
    theta = int(theta + omega * dt) % 360;
}
void Body::compute_net_force(Vect2 forces[]){}
void Body::compute_net_torque(Vect2 torques[]){}

// WORLD CLASS
World::World(float g, std::vector<Body> bodies) {}
void World::update_state(float dt){
    for (Body& b : bodies) {
        b.update_state(dt);
    }
}