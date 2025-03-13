#include "Dino.hpp"

Dino::Dino(Texture2D tex) : texture(tex), velocityY(0), isJumping(false) {
    rect = {50.0f, static_cast<float>(300 - texture.height),
        static_cast<float>(texture.width), static_cast<float>(texture.height)};
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

    if (rect.y >= 300 - rect.height) {
        rect.y = 300 - rect.height;
        isJumping = false;
    }
}

void Dino::Draw() {
    DrawTexture(texture, rect.x, rect.y, WHITE);
}

Rectangle Dino::GetRect() {
    return rect;
}
