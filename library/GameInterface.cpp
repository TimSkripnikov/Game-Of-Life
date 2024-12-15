#include "GameOfLife.hpp"

GameInterface::GameInterface(int argc, char **argv)
{
    start_game(argc, argv);
    is_it_exit = 1;
}

void GameInterface::start_game(int argc, char **argv)
{
    GameState game;
    ParserCommandLine parser_command_line(argc, argv);

    char mode = parser_command_line.get_mode();

    if (mode == '1')
    {
        ParserFile parser_file(parser_command_line.get_input_file());

        parser_file.parse(game);

        print_field(game.get_field());

        while (is_it_exit)
        {

            try
            {
                std::string input = manage_input();

                ParserCommands parser_command;
                parser_command.parse_command(input);
                game_process(game, parser_command_line, parser_command);
            }
            catch (const InvalidCommandException &e)
            {
                std::cerr << "\033[31m" << "Error: " << "\033[0m" << e.what() << "\n";
                std::cerr << "Press ENTER to continue...";

                std::string input2;
                std::getline(std::cin, input2);
                clear_lines(3);
            }
        }
    }
    else if (mode == '2')
    {
        const std::string filenames[] = {"games/game1.live", "games/game2.live", "games/game3.live", "games/game4.live", "games/game5.live"};

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(0, 4);
        int random_number = distrib(gen);

        std::string generated_file = filenames[random_number];

        ParserFile parser_file(generated_file);
        parser_file.parse(game);

        print_field(game.get_field());

        while (is_it_exit)
        {

            try
            {
                std::string input = manage_input();

                ParserCommands parser_command;
                parser_command.parse_command(input);
                game_process(game, parser_command_line, parser_command);
            }
            catch (const InvalidCommandException &e)
            {
                std::cerr << "\033[31m" << "Error: " << "\033[0m" << e.what() << "\n";
                std::cerr << "Press ENTER to continue...";

                std::string input2;
                std::getline(std::cin, input2);
                clear_lines(3);
            }
        }
    }
    else if (mode == '3')
    {
        ParserFile parser_file(parser_command_line.get_input_file());

        parser_file.parse(game);

        print_field(game.get_field());

        GameEngine engine(game, parser_command_line.get_iterations());

        engine.UpdateGameState();

        std::cout << "The field after " << parser_command_line.get_iterations() << " iterations:\n";
        print_field(game.get_field());
        save_to_file(game, parser_command_line.get_output_file());
        is_it_exit = 0;
    }
}

void GameInterface::print_field(const Field &field) const
{

    for (const auto &row : field)
    {
        for (bool cell : row)
        {

            std::cout << (cell ? 'O' : '.') << " ";
        }
        std::cout << '\n';
    }
}

void GameInterface::game_process(GameState &game, ParserCommandLine &parser_command_line, ParserCommands &parser_command)
{
    char command = parser_command.get_command();

    if (command == '1')
    {
        save_to_file(game, parser_command.get_filename());
    }
    else if (command == '2')
    {
        GameEngine engine(game, parser_command.get_iterations());
        engine.UpdateGameState();
        int tmp = game.get_size() + 1;

        clear_lines(tmp);
        print_field(game.get_field());
        std::cout << "";
    }

    else if (command == '3')
    {
        std::cout << "Ending the Game...\n";
        is_it_exit = 0;
    }

    else if (command == '4')
    {
        print_help();
    }
}

void GameInterface::print_help()
{
    std::cout << "\033[32m" << "Game of Life Help\n"
              << "\033[0m"
              << "============================\n\n"
              << "You can specify the name of the input file and the number of steps at startup:\n"
              << "./game <input file> -i <step count> -o <output file>\n\n"
              << "For example:\n"
              << "./build/game game1.live --iterations=2 --output=./out3.live\n\n"
              << "Alternatively, you can play step by step. At startup, you can provide a file\n"
              << "that describes the field in Life 1.06 format. If no file is provided, the default\n"
              << "field will be loaded.\n\n"

              << "\033[32m" << "Commands for step-by-step play:\n"
              << "\033[0m"
              << " - dump <output file>: Saves the current field to the specified file.\n"
              << "   By default, the file is saved as 'out.live'.\n"
              << " - tick <n>: Advances the game by n steps (default is 1).\n"
              << " - exit: Exits the game.\n\n"

              << "\033[32m" << "Additional Information:\n"
              << "\033[0m"
              << " - The field is displayed in real time after each tick.\n"
              << " - Save your progress using the dump command to continue later.\n\n"
              << "Press ENTER to continue...";

    std::string input2;
    std::getline(std::cin, input2);
    clear_lines(25);
}

void GameInterface::clear_lines(int count_lines)
{
    for (int i = 0; i < count_lines; ++i)
        std::cout << "\033[F\033[K";
}

void GameInterface::save_to_file(const GameState &game, const std::string &output_file)
{
    std::ofstream file(output_file);
    if (!file.is_open())
    {
        throw std::runtime_error("It couldn't open file for read: " + output_file);
    }

    file << "#Life " << game.get_game_version() << "\n";

    file << "#N " << game.get_universe_name() << "\n";

    file << "#Size " << game.get_size() << "\n";

    file << "#R B";
    for (int condition : game.get_B_conditions())
    {
        file << condition;
    }
    file << "/S";
    for (int condition : game.get_S_conditions())
    {
        file << condition;
    }
    file << "\n";

    const auto &field = game.get_field();
    for (int row = 0; row < field.size(); ++row)
    {
        for (int col = 0; col < field[row].size(); ++col)
        {
            if (field[row][col])
            {
                file << row + 1 << " " << col + 1 << "\n";
            }
        }
    }

    file.close();
    std::cout << "The data was saved to: " << output_file << ". Press ENTER to continue..." << "\n";

    std::string input2;
    std::getline(std::cin, input2);
    clear_lines(3);
}

std::string GameInterface::manage_input()
{
    std::string input;
    std::getline(std::cin, input);

    size_t end_pos = input.find_last_not_of(" \t\n\r");
    if (end_pos != std::string::npos)
    {
        input.erase(end_pos + 1);
    }
    else
    {
        input.clear();
    }
    return input;
}

// g++ GameState.cpp GameEngine.cpp ParserCommandLine.cpp ParserCommands.cpp ParserFile.cpp GameInterface.cpp main.cpp -o main