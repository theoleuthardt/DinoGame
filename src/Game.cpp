#include "Game.hpp"
#include "raylib.h"
#include <algorithm>

using namespace std;

Game::Game() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(800, 400, "Retro Dino Game");
    SetTargetFPS(60);

    dinoTexture = LoadTexture("assets/dino.png");
    cactusTexture = LoadTexture("assets/cactus.png");
    groundTexture = LoadTexture("assets/ground.png");

    dino = new Dino(dinoTexture);
    score = 0;
    gameOver = false;
}

Game::~Game() {
    UnloadTexture(dinoTexture);
    UnloadTexture(cactusTexture);
    UnloadTexture(groundTexture);
    delete dino;
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    if (!gameOver) {
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) {
            dino->Jump();
        }

        dino->Update();

        if (GetRandomValue(0, 100) < 2) {
            cacti.push_back(Cactus(cactusTexture, 800));
        }

        for (auto &cactus : cacti) {
            cactus.Update();
        }

        cacti.erase(remove_if(cacti.begin(), cacti.end(),
                                   [](Cactus &c) { return c.IsOffScreen(); }),
                    cacti.end());

        for (auto &cactus : cacti) {
            if (CheckCollision(*dino, cactus)) {
                gameOver = true;
            }
        }

        score++;
    }
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
    DrawTexture(groundTexture, 0, 300, WHITE);

    if (!gameOver) {
        dino->Draw();
        for (auto &cactus : cacti) {
            cactus.Draw();
        }
    } else {
        int gameOverTextWidth = MeasureText("GAME OVER", 30);
        DrawText("GAME OVER", GetScreenWidth()/2 - gameOverTextWidth/2, 150, 30, RED);

        int restartTextWidth = MeasureText("Press R to restart!", 20);
        DrawText("Press R to restart!", GetScreenWidth()/2 - restartTextWidth/2, 190, 20, BLACK);
        if (IsKeyPressed(KEY_R)) {
            Reset();
        }

        int exitTextWidth = MeasureText("Press ESC to close the game!", 20);
        DrawText("Press ESC to close the game!", GetScreenWidth()/2 - exitTextWidth/2, 210, 20, BLACK);
    }

    EndDrawing();
}

void Game::Reset() {
    delete dino;
    dino = new Dino(dinoTexture);
    cacti.clear();
    score = 0;
    gameOver = false;
}

bool Game::CheckCollision(Dino &dino, Cactus &cactus) {
    return CheckCollisionRecs(dino.GetRect(), cactus.GetRect());
}
