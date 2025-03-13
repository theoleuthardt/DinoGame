#include "Cactus.hpp"

Cactus::Cactus(Texture2D texture, float x, float y) : texture(texture) {
    rect = {static_cast<float>(x), static_cast<float>(320 - texture.height),
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
    float hitboxWidth = texture.width * 0.8f;
    float hitboxHeight = texture.height * 0.7f;

    float hitboxX = rect.x + (texture.width - hitboxWidth) / 2;
    float hitboxY = rect.y + (texture.height - hitboxHeight);

    return {hitboxX, hitboxY, hitboxWidth, hitboxHeight};
}
