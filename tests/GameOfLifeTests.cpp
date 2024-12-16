#include "../library/GameOfLife.hpp"
#include <gtest/gtest.h>

TEST(ParserCommandLineTest, ValidArgumentsInMode1)
{
    const char *argv[] = {"program_name", "example.live"};
    int argc = 2;

    ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));

    EXPECT_EQ(parser_command_line.get_mode(), '1');
    EXPECT_EQ(parser_command_line.get_input_file(), "example.live");
    EXPECT_THROW(parser_command_line.get_output_file(), std::logic_error);
    EXPECT_THROW(parser_command_line.get_iterations(), std::logic_error);
}

TEST(ParserCommandLineTest, IncorrectArgumentsInMode1)
{
    const char *argv[] = {"program_name", "example.liv"};
    int argc = 2;

    EXPECT_THROW(ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));, std::invalid_argument);
}

TEST(ParserCommandLineTest, ValidArgumentsInMode2)
{
    const char *argv[] = {"program_name"};
    int argc = 1;

    ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));

    EXPECT_EQ(parser_command_line.get_mode(), '2');
    EXPECT_THROW(parser_command_line.get_input_file(), std::logic_error);
    EXPECT_THROW(parser_command_line.get_output_file(), std::logic_error);
    EXPECT_THROW(parser_command_line.get_iterations(), std::logic_error);
}

TEST(ParserCommandLineTest, ValidArgumentsInMode3)
{
    const char *argv[] = {"program_name", "example.live", "-i", "10", "-o", "output.live"};
    int argc = 6;

    ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));

    EXPECT_EQ(parser_command_line.get_mode(), '3');
    EXPECT_EQ(parser_command_line.get_input_file(), "example.live");
    EXPECT_EQ(parser_command_line.get_output_file(), "output.live");
    EXPECT_EQ(parser_command_line.get_iterations(), 10);
}

TEST(ParserCommandLineTest, ValidArgumentsInOtherOrder)
{
    const char *argv[] = {"program_name", "example.live", "-o", "output.live", "-i", "10"};
    int argc = 6;

    ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));

    EXPECT_EQ(parser_command_line.get_mode(), '3');
    EXPECT_EQ(parser_command_line.get_input_file(), "example.live");
    EXPECT_EQ(parser_command_line.get_output_file(), "output.live");
    EXPECT_EQ(parser_command_line.get_iterations(), 10);
}

TEST(ParserCommandLineTest, IncorrectValueOfIterations)
{
    const char *argv[] = {"program_name", "example.live", "-i", "10kf", "-o", "output.live"};
    int argc = 6;

    EXPECT_THROW(ParserCommandLine parser_command_line(argc, const_cast<char **>(argv)), std::invalid_argument);
}

TEST(ParserCommandLineTest, ValidArgumentsInMode3_OtherOptions)
{
    const char *argv[] = {"program_name", "example.live", "--output=output.live", "--iterations=10"};
    int argc = 4;

    ParserCommandLine parser_command_line(argc, const_cast<char **>(argv));

    EXPECT_EQ(parser_command_line.get_mode(), '3');
    EXPECT_EQ(parser_command_line.get_input_file(), "example.live");
    EXPECT_EQ(parser_command_line.get_output_file(), "output.live");
    EXPECT_EQ(parser_command_line.get_iterations(), 10);
}

TEST(ParserCommandLineTest, IncorrectArgumentsInMode3_OtherOptions)
{
    const char *argv[] = {"program_name", "example.live", "--output=output.live"};
    int argc = 3;
    EXPECT_THROW(ParserCommandLine parser_command_line(argc, const_cast<char **>(argv)), std::invalid_argument);
}

TEST(ParserCommandsTest, ValidCommand1)
{
    std::string command = "dump example.live";

    ParserCommands parser_commands;

    parser_commands.parse_command(command);

    EXPECT_EQ(parser_commands.get_command(), '1');
    EXPECT_EQ(parser_commands.get_filename(), "example.live");
    EXPECT_THROW(parser_commands.get_iterations(), std::runtime_error);
}

TEST(ParserCommandsTest, IncorrectCommand1)
{
    std::string command1 = "dump example.liv";
    std::string command2 = "dump";
    ParserCommands parser_commands;

    EXPECT_THROW(parser_commands.parse_command(command1), std::runtime_error);
    EXPECT_THROW(parser_commands.parse_command(command2), std::runtime_error);
}

TEST(ParserCommandsTest, ValidCommand2)
{
    std::string command1 = "tick 20";
    std::string command2 = "t 20";
    std::string command3 = "tick";
    std::string command4 = "t";

    ParserCommands parser_commands;

    parser_commands.parse_command(command1);
    EXPECT_EQ(parser_commands.get_command(), '2');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_EQ(parser_commands.get_iterations(), 20);

    parser_commands.parse_command(command2);
    EXPECT_EQ(parser_commands.get_command(), '2');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_EQ(parser_commands.get_iterations(), 20);

    parser_commands.parse_command(command3);
    EXPECT_EQ(parser_commands.get_command(), '2');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_EQ(parser_commands.get_iterations(), 1);

    parser_commands.parse_command(command4);
    EXPECT_EQ(parser_commands.get_command(), '2');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_EQ(parser_commands.get_iterations(), 1);
}

TEST(ParserCommandsTest, IncorrectCommand2)
{
    std::string command1 = "tick 20df";
    std::string command2 = "t 20asddddddddddd";
    std::string command3 = "tick 0";
    std::string command4 = "tic";

    ParserCommands parser_commands;
    EXPECT_THROW(parser_commands.parse_command(command1), std::runtime_error);

    EXPECT_THROW(parser_commands.parse_command(command2), std::runtime_error);

    EXPECT_THROW(parser_commands.parse_command(command3), std::runtime_error);

    EXPECT_THROW(parser_commands.parse_command(command4), std::runtime_error);
}

TEST(ParserCommandsTest, ValidCommand3)
{
    std::string command1 = "exit";

    ParserCommands parser_commands;

    parser_commands.parse_command(command1);
    EXPECT_EQ(parser_commands.get_command(), '3');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_THROW(parser_commands.get_iterations(), std::runtime_error);
}

TEST(ParserCommandsTest, IncorrectCommand3)
{
    std::string command1 = "exit  ";

    ParserCommands parser_commands;

    EXPECT_THROW(parser_commands.parse_command(command1), std::runtime_error);
    EXPECT_THROW(parser_commands.get_iterations(), std::runtime_error);
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
}

TEST(ParserCommandsTest, ValidCommand4)
{
    std::string command1 = "help";

    ParserCommands parser_commands;

    parser_commands.parse_command(command1);
    EXPECT_EQ(parser_commands.get_command(), '4');
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
    EXPECT_THROW(parser_commands.get_iterations(), std::runtime_error);
}

TEST(ParserCommandsTest, IncorrectCommand4)
{
    std::string command1 = "  help  ";

    ParserCommands parser_commands;

    EXPECT_THROW(parser_commands.parse_command(command1), std::runtime_error);
    EXPECT_THROW(parser_commands.get_iterations(), std::runtime_error);
    EXPECT_THROW(parser_commands.get_filename(), std::runtime_error);
}

TEST(ParserFileTest, ValidFile)
{
    std::string file = "right.live";
    GameState game;
    ParserFile parser_file(file);

    std::string version_test = "1.06";
    std::string universe_test = "game1";
    int size_test = 25;
    std::set<int> B_test = {3};
    std::set<int> S_test = {2, 3};

    parser_file.parse(game);

    EXPECT_EQ(game.get_game_version(), version_test);
    EXPECT_EQ(game.get_universe_name(), universe_test);
    EXPECT_EQ(game.get_size(), size_test);
    EXPECT_EQ(game.get_B_conditions(), B_test);
    EXPECT_EQ(game.get_S_conditions(), S_test);
}

TEST(ParserFileTest, WrongFile)
{
    std::string file = "wrong.live";
    GameState game;
    ParserFile parser_file(file);

    EXPECT_THROW(parser_file.parse(game), std::invalid_argument);
}
