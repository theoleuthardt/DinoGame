#include "Dino.hpp"

Dino::Dino(Texture2D texture)
    : texture(texture), velocityY(0), isJumping(false),
      frameCount(3), currentFrame(0), frameTime(0.1f), frameTimer(0.0f) {
    rect = {50.0f, static_cast<float>(320 - texture.height),
        static_cast<float>(texture.width / frameCount), static_cast<float>(texture.height)};
}

void Dino::Jump() {
    if (!isJumping) {
        velocityY = JUMP_STRENGTH;
        isJumping = true;
    }
}

void Dino::Update() {
    velocityY += GRAVITY;
    rect.y += velocityY;

    if (rect.y >= groundLevel - rect.height) {
        rect.y = groundLevel - rect.height;
        velocityY = 0;
        isJumping = false;
    }

    if (!isJumping) {
        frameTimer += GetFrameTime();
        if (frameTimer >= frameTime) {
            frameTimer = 0.0f;
            currentFrame = (currentFrame + 1) % frameCount;
        }
    }
}

void Dino::Draw() {
    Rectangle source = {static_cast<float>(currentFrame * (texture.width / frameCount)), 0,
                        static_cast<float>(texture.width / frameCount), static_cast<float>(texture.height)};

    DrawTextureRec(texture, source, {rect.x, rect.y}, WHITE);
}

Rectangle Dino::GetRect() {
    return rect;
}
