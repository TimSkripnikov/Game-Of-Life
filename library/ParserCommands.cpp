#include "GameOfLife.hpp"

ParserCommands::ParserCommands() : command(0), iterations(0) {}

bool ParserCommands::has_live_extension(const std::string &filename)
{
    const std::string extension = ".live";
    return filename.size() >= extension.size() &&
           filename.compare(filename.size() - extension.size(), extension.size(), extension) == 0;
}

void ParserCommands::parse_dump(const std::string &input)
{
    std::istringstream stream(input);
    std::string command_part, filename_part;

    stream >> command_part >> filename_part;

    if (filename_part.empty())
    {
        throw InvalidCommandException("dump command requires a filename.");
    }

    if (!has_live_extension(filename_part))
    {
        throw InvalidCommandException("Invalid file extension: Output file must have .live extension.");
    }

    command = '1';
    filename = filename_part;
}

void ParserCommands::parse_tick(const std::string &input)
{
    std::istringstream stream(input);
    std::string command_part;
    stream >> command_part;

    if (command_part != "tick" && command_part != "t")
    {
        throw InvalidCommandException("Invalid command format for tick.");
    }

    command = '2';
    iterations = 1;
    if (!stream.eof())
    {
        std::string iterations_part;
        stream >> iterations_part;

        try
        {
            size_t pos;
            iterations = std::stoi(iterations_part, &pos);

            if (pos != iterations_part.length())
            {
                throw std::invalid_argument("Invalid characters after number.");
            }

            if (iterations <= 0)
            {
                throw std::invalid_argument("Iterations must be a positive integer.");
            }
        }
        catch (const std::invalid_argument &)
        {
            throw InvalidCommandException("tick command requires a valid positive integer without extra characters.");
        }
        catch (const std::out_of_range &)
        {
            throw InvalidCommandException("tick command requires an integer within a valid range.");
        }
    }

    if (!stream.eof())
    {
        throw InvalidCommandException("Invalid input: Unexpected characters after iterations.");
    }
}

void ParserCommands::parse_exit(const std::string &)
{
    command = '3';
}

void ParserCommands::parse_help(const std::string &)
{
    command = '4';
}

void ParserCommands::parse_command(const std::string &input)
{
    if (input.empty())
    {
        parse_tick("tick 1");
    }
    else if (input.find("dump") == 0)
    {

        if (input.size() > 4 && input[4] != ' ')
        {
            throw InvalidCommandException("Unknown command!");
        }
        parse_dump(input);
    }
    else if (input == "tick" || input == "t" || input.find("tick ") == 0 || input.find("t ") == 0)
    {
        parse_tick(input);
    }
    else if (input == "exit")
    {
        parse_exit(input);
    }
    else if (input == "help")
    {
        parse_help(input);
    }
    else
    {
        throw InvalidCommandException("Unknown command!");
    }
}

char ParserCommands::get_command() const
{
    return command;
}

const std::string &ParserCommands::get_filename() const
{
    if (command != '1')
    {
        throw InvalidCommandException("Filename not available for this command.");
    }
    return filename;
}

int ParserCommands::get_iterations() const
{
    if (command != '2')
    {
        throw InvalidCommandException("Iterations not available for this command.");
    }
    return iterations;
}
