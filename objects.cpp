#include <vector>
#include <tuple>
#include "raylib.h"
#include "objects.h"
#include <iostream>

// System Object
System::System(std::vector<Body> bodies) : bodies(bodies) {}

std::tuple<Vector2, float, float, std::vector<Body>> System::get_state(){
    // Return the current pos, vel, acc of each body and the system variables
    return {gravity, air_resistance, time, bodies};
}

void System::set_state(Vector2 g, float ar, float t){
    gravity = g;
    air_resistance = ar;
    time = t;
}

void System::update_state() {



    // time += dt;
    // for (Body b : bodies) {
    //     auto [position, velocity, acceleration] = b.get_rel_state();
    //     float new_posX = position.x + velocity.x*dt;
    //     float new_posY = position.y + velocity.y*dt;
    //     Vector2 new_pos = {new_posX, new_posY};

    //     float new_velX = velocity.x + acceleration.x*dt;
    //     float new_velY = velocity.y + acceleration.y*dt;
    //     Vector2 new_vel = {new_velX, new_velY};
        
    //     b.set_rel_state(new_pos, new_vel, acceleration);
        
    // }
}

// Body Object
// All bodies are rectangles for now
Body::Body(int x, int y, int w, int h, float m) {
        pos.x = x;
        pos.y = y;
        width = w;
        height = h;
        mass = m;
        vel = {0.001, 0};
        acc = {0,0};
    }

std::tuple<Vector2, Vector2, Vector2> Body::get_rel_state(){
    return {pos,vel,acc};
}

void Body::set_rel_state(Vector2 position, Vector2 velocity, Vector2 acceleration) {
    pos = position;
    vel = velocity;
    acc = acceleration;
}

