#ifndef DINO_HPP
#define DINO_HPP
#include "raylib.h"

/**
 * @brief The Dino class represents the player character in the game.
 */
class Dino {
public:
    /**
     * @brief Construct a new Dino object.
     * @param texture The texture for the dino
     */
    explicit Dino(Texture2D texture);

    /**
     * @brief Make the dino jump if it is not already jumping.
     */
    void Jump();

    /**
     * @brief Let the dino fall if it is not on the ground and update the frame for the walking animation.
     */
    void Update();

    /**
     * @brief Draw the dino to the screen.
     */
    void Draw();

    /**
     * @brief Get the rectangle that represents the dinos position and size (hitbox).
     * @return The rectangle that represents the dinos hitbox
     */
    Rectangle GetRect();

private:
    /**
     * @brief The texture for the dino (3 frames for walking animation)
     */
    Texture2D texture;

    /**
     * @brief The rectangle that represents the dinos hitbox
     */
    Rectangle rect;

    /**
     * @brief The vertical velocity of the dino (positive is down)
     */
    float velocityY;

    /**
     * @brief A flag to indicate if the dino is currently jumping
     */
    bool isJumping;

    /**
     * @brief Gravity constant to let the dino fall
     */
    static constexpr float GRAVITY = 0.4;

    /**
     * @brief The dino's strength of the jump against gravity
     */
    static constexpr float JUMP_STRENGTH = -10;

    /**
     * @brief The y-coordinate of the ground level to let the dino stand on the ground
     */
    int groundLevel = 320;

    /**
     * @brief The number of frames for the walking animation
     */
    int frameCount;

    /**
     * @brief The current frame for the walking animation
     */
    int currentFrame;

    /**
     * @brief The time for each frame of the walking animation
     */
    float frameTime;

    /**
     * @brief The timer to switch to the next frame of the walking animation
     */
    float frameTimer;
};

#endif //DINO_HPP