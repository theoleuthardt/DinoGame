#ifndef DINO_HPP
#define DINO_HPP
#include "raylib.h"

class Dino {
public:
    explicit Dino(Texture2D texture);
    void Jump();
    void Update();
    void Draw();
    Rectangle GetRect();

private:
    Texture2D texture;
    Rectangle rect;
    float velocityY;
    bool isJumping;
    static constexpr float GRAVITY = 0.4;
    static constexpr float JUMP_STRENGTH = -10;
    int groundLevel = 320;
    int frameCount;
    int currentFrame;
    float frameTime;
    float frameTimer;
};

#endif //DINO_HPP