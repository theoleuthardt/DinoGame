#include "Cactus.hpp"

Cactus::Cactus(Texture2D texture, float x) : texture(texture) {
    rect = {static_cast<float>(x), static_cast<float>(300 - texture.height),
        static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

void Cactus::Update() {
    rect.x -= SPEED;
}

void Cactus::Draw() {
    DrawTexture(texture, rect.x, rect.y, WHITE);
}

bool Cactus::IsOffScreen() {
    return rect.x + rect.width < 0;
}

Rectangle Cactus::GetRect() {
    return rect;
}
