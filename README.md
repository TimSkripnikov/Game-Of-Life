# Game of Life

**Game of Life** is an implementation of John Conway's famous cellular automaton. This project provides tools for simulating, customizing, and interacting with the game, including flexible rule sets, game state management, and command-line control.

## 📖 Description

The Game of Life is a zero-player game where cells on a grid evolve based on a set of simple rules. Despite its simplicity, it can generate complex and fascinating patterns.

This project serves as a practical exercise in algorithm design, grid-based state management, and simulation systems. It helps develop skills applicable to game development, visualization, and modeling of complex systems with simple rule sets.

This project was created as part of the NSU course *"Object Oriented Programming in C++"*.

### Basic Rules:
1. **Birth:** A dead cell becomes alive if it has exactly 3 live neighbors
2. **Survival:** A live cell remains alive if it has 2 or 3 live neighbors
3. **Death:** In all other cases, cells die or remain dead

This implementation allows for customizable rules, enabling the creation of unique universes.

## 🛠️ Features

- **Flexible Rules:** Customize the rules for cell birth (`B`) and survival (`S`)
- **File Support:** Save and load game states using `.live` files
- **Simulation Control:** Step through iterations or simulate multiple generations in one command
- **Command-Line Interface:** Intuitive commands for interacting with the game
- **Dynamic Grid Size:** Support for any square grid size

## 🚀 Getting Started

### Prerequisites

- **C++17** or higher;
- A C++ compiler (e.g., GCC, Clang, or MSVC);
- CMake (optional, for build automation).

### Cloning the Repository

```bash
git clone https://github.com/TimSkripnikov/Game-Of-Life.git
cd Game-Of-Life
```

### Building the Project

```bash
mkdir build
cmake -S . -B build
cmake --build build
```

### Running the Game
```bash
./build/game [options]
```
### Command-Line Options

- `-i x`: count of iterations;
- `--iterations=x`: count of iterations;
- `-o <file>`: save the state after x iterations to a `.live` file;
- `--output=filename`: save the state after x iterations to a `.live` file.

Examples:
```bash
./build/game input_file.live -i 20 -o output_file.live
./build/game input_file.live --iterations=20 -o output_file.live
./build/game input_file.live
./build/game
```

### Interactive Commands in Game

- `tick <n>`: Advance the simulation by n steps;
- `dump <filename>`: Save the current state to a file;
- `help`: Display a help menu;
- `exit`: Quit the program.

### 📚 File Format

The `.live` file format includes:
1. Version of the Game;
2. Name of the Game;
3. The grid size;
4. Game rules (B and S conditions);
5. Coordinates of live cells (x; y).

```bash
#Life 1.06
#N game1
#Size 25
#R B3/S23
10 15
9 16
9 17
10 17
11 17
10 20
11 20
9 21
11 21
11 22
```
