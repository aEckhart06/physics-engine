// #include "raylib-cpp.hpp"
#include "../include/objects.h"
#include "raylib.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Vector2 dims_meters = {16, 9}; // 16m X 9m
    float m = 50; // Scale factor: Number of pixes for 1 meter
    float screenWidth = dims_meters.x*m;
    float screenHeight = dims_meters.y*m;

    InitWindow(screenWidth, screenHeight, "test");
    SetTargetFPS(60);

    float mass = 10;
    float mom_I = (1/3)*mass*50*50;

    RigidBody rect = RigidBody(100, 20, mass, mom_I, {screenWidth/2, screenHeight/4}, {{1,0},{0,1}});
    // RigidBody rect2 = RigidBody(40, 10, mass, mom_I, {(screenWidth+75)/2, (screenHeight-100)/2}, {{1,0},{0,1}});

    // Global list of rigid bodies
    vector<RigidBody> bodies = {rect};
    int rot = 0;

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();
        for (RigidBody& rb : bodies) {
            rb.compute_net_force(dt);
            rb.update_state(dt);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (RigidBody& rb : bodies) {
            rb.draw();
        }
        
        EndDrawing();
    }
    CloseWindow();
    


    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}