#include "raylib-cpp.hpp"
#include "raylib.h"
#include <vector>

#include "../headers/bouncing_square.h"

void bouncing_ball(int screenWidth, int screenHeight) {

    Vector2 pos = { 400.0f, 300.0f };
    Vector2 vel = { 200.0f, 100.0f }; // Pixels per second
    Vector2 size = {20,20}; 

    while (!WindowShouldClose())
    {
        // INPUT KEYS
        if (IsKeyPressed(KEY_UP)) { if (vel.y > 0) {vel.y=vel.y*-1;}}
        if (IsKeyPressed(KEY_DOWN)) { if (vel.y < 0) {vel.y=vel.y*-1;}}
        if (IsKeyPressed(KEY_LEFT)) { if (vel.x > 0) {vel.x=vel.x*-1;}}
        if (IsKeyPressed(KEY_RIGHT)) { if (vel.x < 0) {vel.x=vel.x*-1;}}
        
        float dt = GetFrameTime();
        

        pos.x += vel.x * dt;
        pos.y += vel.y * dt;
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (pos.y + size.y >= screenHeight || pos.y <= 0) {
            vel.y = vel.y * -1;
        }
        if (pos.x + size.x >= screenWidth || pos.x <= 0) {
            vel.x = vel.x *= -1;
        }

        DrawRectangleV(pos, size, RED);
        
        // Object methods.
        EndDrawing();
    }
    CloseWindow();

}