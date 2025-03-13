#ifndef GAME_HPP
#define GAME_HPP
#include "raylib.h"
#include "Dino.hpp"
#include "Cactus.hpp"
#include <vector>

using namespace std;

/**
 * @brief The Game class is responsible for running the game loop,
 * updating the game state, and drawing the game objects.
 */
class Game {
public:
    /**
     * @brief Construct a new Game object to initialize the game window and load the textures.
     */
    Game();

    /**
     * @brief Destroy the Game object if the game window is closed.
     */
    ~Game();

    /**
     * @brief Run the game loop to update and draw the game objects (loop until the window is closed).
     */
    void Run();

private:
    /**
     * @brief Update the game state for the current frame. If the game is not over yet, the dino can jump and the cacti
     * are moving towards the dino. On a random interval, a new cactus is spawned. If the dino collides with a cactus,
     * the game is over and can be restarted! The score is increased every frame.
     */
    void Update();

    /**
     * @brief Draw the game objects to the screen. If the game is over, the game over screen is displayed with the
     * hints to restart the game or close the window. The highscore is saved if the player wants to play again.
     *
     */
    void Draw();

    /**
     * @brief Reset the game state if the player wants to play again. It deletes the dino object and creates a new one,
     * deletes all cacti and creates a new one at the beginning of the game. Also the score is reset to 0 and the game's
     * highscore is set to the maximum of the current highscore and the current score.
     */
    void Reset();

    /**
     * @brief Saves the high score to a dat-file. If the file does not exist, it will be created.
     */
    void Save() const;

    /**
     * @brief Loads the high score from a dat-file. If the file does not exist, the high score will be 0.
     */
    void Load();

    /**
     * @brief Checks for collision between the dino and a cactus. It uses the rectangle collision detection from raylib.
     * @param dino The dino object
     * @param cactus The cactus object
     * @return true if the dino and cactus are colliding
     * @return false if the dino and cactus are not colliding
     */
    static bool CheckCollision(Dino &dino, Cactus &cactus);

    /**
     * @brief The texture for the dino (3 frames)
     */
    Texture2D dinoTexture{};

    /**
     * @brief The texture for the cactus
     */
    Texture2D cactusTexture{};

    /**
     * @brief The texture for the ground
     */
    Texture2D groundTexture{};

    /**
     * @brief The dino object
     */
    Dino *dino;

    /**
     * @brief The vector of cactus objects to save all the cacti
     */
    vector<Cactus> cacti;

    /**
     * @brief The displayed score of the player
     */
    int score;

    /**
     * @brief The highscore of the player which will be saved
     */
    int highscore;

    /**
     * @brief The state if the game is over
     */
    bool gameOver;

    /**
     * @brief The timer to manage the jump hint to disappear after a certain time
     */
    float hintTimer = 0.0f;
};

#endif //GAME_HPP
