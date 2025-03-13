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
    highscore = 0;
    gameOver = false;
    cacti.push_back(Cactus(cactusTexture, 800, 330 - cactusTexture.height));
}

Game::~Game() {
    UnloadTexture(dinoTexture);
    UnloadTexture(cactusTexture);
    UnloadTexture(groundTexture);
    delete dino;
    CloseWindow();
}

void Game::Run() {
    Load();

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

        static int frameCounter = 0;
        frameCounter++;
        int spawnInterval = max(20, 50 - score / 1000);
        int spawnChance = max(2, 8 - score / 2500);

        if (frameCounter >= spawnInterval) {
            frameCounter = 0;

            if (GetRandomValue(1, spawnChance) == 1) {
                bool canSpawn = true;
                for (auto &cactus : cacti) {
                    if (cactus.GetRect().x > GetScreenWidth() * 2/3) {
                        canSpawn = false;
                        break;
                    }
                }

                if (canSpawn) {
                    cacti.push_back(Cactus(cactusTexture, 800, 330 - cactusTexture.height));
                }
            }
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
    DrawText(TextFormat("Highscore: %d", highscore), 10, 30, 20, BLACK);
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
        DrawText("Press ESC to close the game!", GetScreenWidth()/2 - exitTextWidth/2, 220, 20, BLACK);

        int saveTextWidth = MeasureText("(Your highscore will be saved!)", 20);
        DrawText("(Your highscore will be saved!)", GetScreenWidth()/2 - saveTextWidth/2, 240, 20, BLACK);

        Save();
    }

    EndDrawing();
}

void Game::Reset() {
    delete dino;
    dino = new Dino(dinoTexture);
    cacti.clear();
    highscore = max(highscore, score);
    score = 0;
    gameOver = false;
    cacti.push_back(Cactus(cactusTexture, 900, 300 - cactusTexture.height));
}

void Game::Save() {
    FILE *file = fopen("save.dat", "wb");
    if (file) {
        fwrite(&highscore, sizeof(highscore), 1, file);
        fclose(file);
    } else {
        TraceLog(LOG_WARNING, "Failed to save highscore");
    }
}

void Game::Load() {
    FILE *file = fopen("save.dat", "rb");
    if (file) {
        fread(&highscore, sizeof(highscore), 1, file);
        fclose(file);
    } else {
        TraceLog(LOG_WARNING, "Failed to load highscore");
    }
}

bool Game::CheckCollision(Dino &dino, Cactus &cactus) {
    return CheckCollisionRecs(dino.GetRect(), cactus.GetRect());
}
