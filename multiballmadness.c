//  Light and Dark, with multiple balls in C using raylib
#include <stdbool.h>
#include <stdio.h>
#include "raylib.h"
#include "types.h"

// Global constants
const int screenWidth = 800;
const int screenHeight = 450;
const float ballRadius = 10;
const int targetFPS = 60;
const Vector2 blockSize = { 20, 20 };
const int colorBlockWidth = 10;

void InitGame() {
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "MultiBall Madness");
    SetTargetFPS(targetFPS);
}

void InitBalls(ballArray *balls) {
    const ball white = { {220, 10}, {-1, -1}, LIGHTGRAY};
    const ball black = { {10, 10}, {1, 1}, DARKGRAY};
    appendBall(balls, white);
    appendBall(balls, black);
}

void InitBoard(blockArray *board) {
    for (int i = 0; i < 200; i++) {
        block newLightBlock = { {(float)(i%colorBlockWidth)*blockSize.x,(float)(i/colorBlockWidth)*blockSize.y},LIGHTGRAY};
        block newDarkBlock = { {((float)(i%colorBlockWidth)*blockSize.x)+(10 * blockSize.x),(float)(i/colorBlockWidth)*blockSize.y},DARKGRAY};
        appendBlock(board, newLightBlock);
        appendBlock(board, newDarkBlock);
    }
}

// Update Functions
void UpdateBalls(ballArray *balls) {
    return;
}

void CheckBallCollisions(ballArray *balls, blockArray *board) {
    return;
}

// Render Functions
void RenderBoard(const blockArray *board) {
    for (int i = 0; i < board->count; i++) {
        DrawRectangleV(board->values[i].position, blockSize, board->values[i].color);
    }
}

void RenderBalls(const ballArray *balls) {
    for (int i = 0; i < balls->count; i++) {
        Vector2 highlight = {balls->values[i].position.x - (ballRadius/4), balls->values[i].position.y - (ballRadius/4)};
        DrawCircleV(balls->values[i].position, ballRadius, balls->values[i].color);
        DrawCircleV(highlight, 3, RAYWHITE);
    }
}

int main(void) {
    blockArray blocks = {NULL, 0, 0 };
    ballArray balls = {NULL, 0, 0 };
    bool pause = false;
    int frameCount = 0;

    InitGame();
    InitBalls(&balls);
    InitBoard(&blocks);

    while (!WindowShouldClose()) {
        // Update Board
        if (IsKeyPressed(KEY_SPACE)) pause = !pause;
        if (IsKeyPressed(KEY_Q)) break;

        if (!pause) {
            UpdateBalls(&balls);
            CheckBallCollisions(&balls,&blocks);
        }
        else frameCount++;

        // Render Board
        BeginDrawing();
        ClearBackground(RAYWHITE);
        RenderBoard(&blocks);
        RenderBalls(&balls);
        DrawText("PRESS SPACE to PAUSE, Q to QUIT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);
        if (pause && ((frameCount/30)%2)) DrawText("PAUSED", 350, 200, 30, GRAY);
        DrawFPS(10,10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}