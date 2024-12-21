# Game of Life

**Game of Life** is an implementation of John Conway's famous cellular automaton. This project provides tools for simulating, customizing, and interacting with the game, including flexible rule sets, game state management, and command-line control. The project was created as part of a university course on ‘Object Oriented Programming’.

## 📖 Description

The Game of Life is a zero-player game where cells on a grid evolve based on a set of simple rules. Despite its simplicity, it can generate complex and fascinating patterns.

### Basic Rules:
1. **Birth:** A dead cell becomes alive if it has exactly 3 live neighbors.
2. **Survival:** A live cell remains alive if it has 2 or 3 live neighbors.
3. **Death:** In all other cases, cells die or remain dead.


This implementation allows for customizable rules, enabling the creation of unique universes. The programme supports processing of different rules. 

## 🛠️ Features

- **Flexible Rules:** Customize the rules for cell birth (`B`) and survival (`S`).
- **File Support:** Save and load game states using `.live` files.
- **Simulation Control:** Step through iterations or simulate multiple generations in one command.
- **Command-Line Interface:** Intuitive commands for interacting with the game.
- **Dynamic Grid Size:** Support for any square grid size.

## 🚀 Getting Started

### Prerequisites

- **C++17** or higher
- A C++ compiler (e.g., GCC, Clang, or MSVC)
- CMake (optional, for build automation)

### Cloning the Repository

```bash
git clone https://github.com/TimSkripnikov/Game-Of-Life.git
cd Game-Of-Life

### Building the Project

```bash
mkdir build
cmake -S . -B build
cmake --build build
