#ifndef CACTUS_H
#define CACTUS_H
#include "raylib.h"

class Cactus {
public:
    Cactus(Texture2D texture, float x);
    void Update();
    void Draw();
    bool IsOffScreen();
    Rectangle GetRect();

private:
    Texture2D texture;
    Rectangle rect;
    static constexpr float SPEED = 5;
};

#endif