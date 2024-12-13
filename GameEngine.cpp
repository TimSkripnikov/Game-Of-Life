#include "GameOfLife.hpp"

// Constructor: Initializes the game engine with a reference to the GameState object
GameEngine::GameEngine(GameState &ReceivedGameState, int iterations)
    : CurrentGameState(ReceivedGameState),
      received_number_of_iterations(iterations)
{
}

// Updates the field based on the rules of the game
void GameEngine::UpdateGameState()
{

    int rows = CurrentGameState.get_size();
    int cols = CurrentGameState.get_size();

    for (int i = 0; i < received_number_of_iterations; ++i)
    {

        // Create a copy of the field to store the updated state

        Field currentField = CurrentGameState.get_field();
        Field newField = currentField;

        // Retrieve birth and survival conditions from the game state
        std::set<int> B_conditions = CurrentGameState.get_B_conditions();
        std::set<int> S_conditions = CurrentGameState.get_S_conditions();

        // Iterate through each cell in the field
        for (int x = 0; x < rows; ++x)
        {
            for (int y = 0; y < cols; ++y)
            {
                // Count the number of alive neighbors
                int neighbors = countNeighbors(currentField, x, y);

                // Determine the new state based on the current state and conditions
                if (currentField[x][y]) // Cell is currently alive
                {
                    // Survives only if it satisfies survival conditions
                    newField[x][y] = S_conditions.count(neighbors) > 0;
                }
                else // Cell is currently dead
                {
                    // Becomes alive if it satisfies birth conditions
                    newField[x][y] = B_conditions.count(neighbors) > 0;
                }
            }
        }

        CurrentGameState.set_field(newField); // Return the updated field
    }
    CurrentGameState.set_count_of_iterations(
        CurrentGameState.get_count_of_iterations() + received_number_of_iterations);
}

// Counts the number of alive neighbors for the cell at (x, y)
int GameEngine::countNeighbors(const Field &field, int x, int y)
{
    int rows = field.size();
    int cols = field[0].size();
    int count = 0;

    // Offsets for all 8 possible neighbors (relative to the current cell)
    std::vector<std::pair<int, int> > directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    // Calculate neighbor positions with toroidal wrapping
    for (const auto &[dx, dy] : directions)
    {
        int nx = (x + dx + rows) % rows; // Wrap around vertically
        int ny = (y + dy + cols) % cols; // Wrap around horizontally

        if (field[nx][ny]) // If the neighbor is alive, increment the count
        {
            ++count;
        }
    }

    return count;
}
