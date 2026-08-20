#pragma once
#include <vector>
#include <tuple>
#include "raylib-cpp-utils.hpp"

class Body {
private:
    float mass; // mass in kg
public:
    int width;
    int height;
    Vector2 pos;
    Vector2 vel;
    Vector2 acc;


    Body(int x, int y, int w, int h, float m);

    std::tuple<Vector2, Vector2, Vector2> get_rel_state();

    void set_rel_state(Vector2 position, Vector2 velocity, Vector2 acceleration);
};

class System {
private:
    Vector2 gravity = {0, 9.81};
    float air_resistance = 0;
    float time = 0;
    std::vector<Body> bodies;
public:
    System(std::vector<Body> bodies);

    std::tuple<Vector2, float, float, std::vector<Body>> get_state();

    void set_state(Vector2 g, float ar, float t);

    void update_state();
};

