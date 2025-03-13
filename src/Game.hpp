#ifndef GAME_HPP
#define GAME_HPP
#include "raylib.h"
#include "Dino.hpp"
#include "Cactus.hpp"
#include <vector>

using namespace std;

class Game {
public:
    Game();
    ~Game();
    void Run();

private:
    void Update();
    void Draw();
    void Reset();
    bool CheckCollision(Dino &dino, Cactus &cactus);

    Texture2D dinoTexture;
    Texture2D cactusTexture;
    Texture2D groundTexture;
    Dino *dino;
    vector<Cactus> cacti;
    int score;
    bool gameOver;
};

#endif //GAME_HPP
