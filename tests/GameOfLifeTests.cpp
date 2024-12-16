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
