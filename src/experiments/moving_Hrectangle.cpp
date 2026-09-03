#include "include/moving_Hrectangle.h"
#include "raylib.h"
#include <vector>

void moving_Hrectangle(int screenWidth, int screenHeight) {
    Vector2 rect_size = {100, 20};
    Vector2 pos = {float (screenWidth/2-rect_size.x/2), float (screenHeight/2-rect_size.y/2)};
    Vector2 vel = {0.0f,0.0f};
    Vector2 acc = {0.0f,0.0f};

    while(!WindowShouldClose()) {

        float dt = GetFrameTime();

        // accelerate at a constant rate while key is down
        if (IsKeyDown(KEY_LEFT)) {
            acc.x = -100;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            acc.x = 100;
        }
            
        
        vel.x += acc.x * dt;
        vel.y += acc.y * dt;
        pos.x += vel.x * dt;
        pos.y += vel.y * dt;

        acc = {-1*vel.x,0};

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleV(pos, rect_size, RED);

        EndDrawing();
    }
    CloseWindow();
}