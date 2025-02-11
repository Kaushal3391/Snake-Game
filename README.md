# Snake Game

## Description
This is a simple terminal-based Snake Game implemented in C++. The game is played on a 20x20 grid, and the objective is to navigate the snake to eat food while avoiding collisions with itself and the grid boundaries.

## Features
- Terminal-based gameplay
- Snake movement using `W`, `A`, `S`, `D` keys
- Random food placement
- Growing snake upon eating food
- Score tracking
- Game over when the snake collides with itself or the wall

## Requirements
- A C++ compiler (MinGW for Windows, GCC for Linux/macOS)
- Terminal to run the compiled executable

## Compilation and Execution

### Windows (MinGW)
```sh
 g++ -o snake_game snake_game.cpp -std=c++11
 snake_game.exe
```

### Linux/macOS (GCC)
```sh
 g++ -o snake_game snake_game.cpp -std=c++11
 ./snake_game
```

## Controls
- `W` - Move Up
- `A` - Move Left
- `S` - Move Down
- `D` - Move Right

## How to Play
1. Run the compiled executable.
2. Use `W`, `A`, `S`, `D` keys to navigate the snake.
3. The snake grows when it eats food (`*`).
4. The game ends if the snake collides with the wall or itself.
5. The final score is displayed when the game ends.

## Code Overview
- `Position` struct: Stores coordinates (x, y) of the snake and food.
- `SnakeGame` class:
  - Handles snake movement and game logic.
  - Generates random food placement.
  - Detects collisions and updates score.
  - Uses `system("cls")` for screen clearing (Windows).
- Uses `<conio.h>` for non-blocking keyboard input (_kbhit() and _getch()).
- Uses `<chrono>` and `<thread>` for controlling game speed.

## Notes
- The game runs in a terminal and does not use any external libraries.
- Uses `_kbhit()` and `_getch()` from `<conio.h>`, which may require modification for compatibility with non-Windows platforms.

Enjoy the game!

