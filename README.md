# Dino Game 🦖🎮

### Description
Welcome to the iconic Dino Game known from your Google browser! In this endless runner game, you control a pixelated dinosaur running through the desert,
dodging obstacles and aiming for the highest score. Jump over cacti and see how far you can go!

### Features
- **Classic Gameplay:** Inspired by the well-known browser dinosaur game
- **Progressive Difficulty:** The game speeds up over time, making it more challenging
- **Simple Controls:** Easy-to-learn, hard-to-master mechanics

### Keyboard Controls
- **Spacebar:** Jump
- **R:** Restart the game
- **ESC:** Exit the game

### Resources

- Library: [Raylib Website](https://www.raylib.com/) [Raylib Github](https://github.com/raysan5/raylib/tree/master)
- CMakeList Template: [CMakeList by tupini07](https://github.com/tupini07/raylib-cpp-cmake-template/blob/main/CMakeLists.txt)
- Game Assets: [Dino Game Assets](https://www.spriters-resource.com/browser_games/googledinosaurrungame/sheet/78171/)
- CropImages: [iloveimg Image Cropper](https://www.iloveimg.com/crop-image)
- RemoveBG for Game Assets: [RemoveBG Tool](https://www.remove.bg/)
- Generative AI for fixing some bugs: [ClaudeAI](https://claude.ai/) [ChatGPT](https://chatgpt.com/)

### Installation
#### Download build from Github
- Download the latest release from the [Releases](https://github.com/theoleuthardt/DinoGame/releases) page
- Extract the zip file
- Run the executable

#### Build from source
1. Requirements/Dependencies
    - **Windows:** [Visual Studio](https://visualstudio.microsoft.com/) or [MinGW](http://www.mingw.org/)
    - **Linux:** `g++`, `make`, `cmake`
    - **MacOS:** `g++`, `make`, `cmake`
      </br></br>
2. Clone the repository
```bash
git clone https://github.com/theoleuthardt/DinoGame.git
```

3. Build the project
```bash
cd DinoGame
mkdir build
cd build
cmake ..
cmake --build .
```

4. Run the executable
    - **Windows**
      ```bash
      cd build
      DinoGame.exe
      ```

    - **Linux/MacOS**
      ```bash
      cd build
      ./DinoGame
      ```
