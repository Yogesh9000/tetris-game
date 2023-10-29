# Tetris Game with Raylib

This is a classic Tetris game implemented in C++ using the Raylib library. Enjoy
the nostalgia of one of the most iconic video games in history.

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [How to Play](#how-to-play)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

### Prerequisites

Before you begin, ensure you have met the following requirements:

- C++ development environment (GCC, Clang, or Visual Studio)
- [Raylib library](https://www.raylib.com/)

### Installation

1. Clone this repository:

   ```bash
   git clone https://github.com/yogesh9000/tetris-game.git
   ```

2. Navigate to the project directory:

   ```bash
   cd tetris-game
   ```

3. Compile the game:

   ```bash
   cmake -S . -B build
   cmake --build build
   ```

## How to Play

Simply run the game by executing the compiled binary:

```bash
./build/tetris
```

Your goal is to clear as many lines as possible by arranging the falling
tetrominoes. When a line is completely filled, it will disappear, and you'll
earn points. The game ends when the pieces stack up to the top of the playfield.

## Controls

- **Left Arrow**: Move the current tetromino left.
- **Right Arrow**: Move the current tetromino right.
- **Up Arrow**: Rotate the current tetromino.

Have fun playing Tetris! If you encounter any issues or have suggestions for
improvements, feel free to open an issue or contribute to the project. Enjoy the
game!
