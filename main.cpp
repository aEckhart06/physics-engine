// #include "raylib-cpp.hpp"
#include "headers/objects.h"
#include "raylib.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {

    

    Vector2 dims_meters = {16, 9}; // 16m X 9m
    float m = 50; // Scale factor: Number of pixes for 1 meter
    int screenWidth = dims_meters.x*m;
    int screenHeight = dims_meters.y*m;

    InitWindow(screenWidth, screenHeight, "test");
    SetTargetFPS(60);

    // Global list of rigid bodies
    vector<RigidBody> bodies = {};

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // DrawTriangle(top, left, right, RED); 
        EndDrawing();
    }
    CloseWindow();
    


    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}