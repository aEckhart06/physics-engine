// #include "raylib-cpp.hpp"
#include "headers/objects.h"
#include "raylib.h"
#include <vector>
#include <iostream>

int main() {
    

    Vector2 dims_meters = {16, 9}; // 16m X 9m
    float m = 50; // Scale factor: Number of pixes for 1 meter
    int screenWidth = dims_meters.x*m;
    int screenHeight = dims_meters.y*m;

    InitWindow(screenWidth, screenHeight, "test");
    SetTargetFPS(60);

    Vector2 top = {float(screenWidth/2), float(screenHeight/2)};
    Vector2 left = {top.x-0.5, top.y+1.732};
    Vector2 right = {top.x+0.5, top.y+1.732};

    Vector2 center = {float(screenWidth/2), float(screenHeight/2)};
    int sides = 3;
    int radius = 30;
    float rot = -90.0;

    Vector2 pos = center;
    Vector2 vel = {0.0f*m,0.0f*m};
    Vector2 acc = {0.0f*m,9.81f*m};
    float total_t = 0;

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        vel.x = vel.x + acc.x*dt;
        vel.y = vel.y + acc.y*dt;

        pos.x = pos.x + vel.x*dt;
        pos.y = pos.y + vel.y*dt;

        total_t+= dt;
        if (total_t >=1.0) {
            std::cout << vel.y << std::endl;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        // DrawPoly(pos, sides, radius, rot, RED); 
        DrawTriangle(top, left, right, RED); 
        EndDrawing();
    }
    CloseWindow();
    


    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}