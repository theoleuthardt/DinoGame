#ifndef CACTUS_H
#define CACTUS_H
#include "raylib.h"

/**
 * @brief The Cactus class represents an obstacle in the game.
 */
class Cactus {
public:
    /**
     * @brief Construct a new Cactus object
     * @param texture The texture for the cactus
     * @param x The x-coordinate of the cactus
     * @param y The y-coordinate of the cactus
     */
    Cactus(Texture2D texture, float x, float y);

    /**
     * @brief Update the cactus position with a constant speed
     */
    void Update();

    /**
     * @brief Draw the cactus to the screen
     */
    void Draw();

    /**
     * @brief Check if the cactus is off the screen
     * @return True if the cactus is off the screen, false otherwise
     */
    bool IsOffScreen();

    /**
     * @brief Get the rectangle that represents the cactus position and size (hitbox) for collision checking
     * @return The rectangle that represents the cactus hitbox
     */
    Rectangle GetRect();

private:
    /**
     * @brief The texture for the cactus
     */
    Texture2D texture;

    /**
     * @brief The rectangle that represents the cactus hitbox
     */
    Rectangle rect;

    /**
     * @brief The speed constant to move the cacti to the left
     */
    static constexpr float SPEED = 5;
};

#endif