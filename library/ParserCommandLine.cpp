#include "GameOfLife.hpp"

ParserCommandLine::ParserCommandLine(int argc, char **argv)
    : mode('0'), iterations(0)
{
    parse(argc, argv);
}

bool ParserCommandLine::has_live_extension(const std::string &filename)
{
    const std::string extension = ".live";
    return filename.size() > extension.size() &&
           filename.compare(filename.size() - extension.size(), extension.size(), extension) == 0;
}

void ParserCommandLine::parse(int argc, char **argv)
{
    if (argc == 2)
    {
        input_file = argv[1];
        if (!has_live_extension(input_file))
        {
            throw std::invalid_argument("Invalid file extension: Input file must have .live extension.");
        }
        mode = '1';
    }
    else if (argc == 1)
    {
        mode = '2';
    }
    else if (argc >= 4)
    {
        input_file = argv[1];

        if (parse_args_iterations(argc, argv) || parse_args_output(argc, argv))
        {
            throw std::invalid_argument("Error parsing arguments!");
        }
        mode = '3';
    }
    else
    {
        throw std::invalid_argument("Invalid arguments: Unexpected number of parameters.");
    }
}

bool ParserCommandLine::parse_args_iterations(int argc, char **argv)
{
    int ind_iter = 0;
    std::string iterations_arg;

    while ((ind_iter < (argc - 1)) &&
           !((std::string(argv[ind_iter]) == "-i") || (std::string(argv[ind_iter]).substr(0, 13) == "--iterations=")))
    {
        ++ind_iter;
    }

    if (std::string(argv[ind_iter]) == "-i" && (ind_iter < (argc - 1)))
    {
        iterations_arg = argv[ind_iter + 1];
    }
    else if (std::string(argv[ind_iter]).substr(0, 13) == "--iterations=")
    {
        iterations_arg = std::string(argv[ind_iter]).substr(13);
    }
    else
    {
        return true;
    }

    std::regex number_regex("^[0-9]+$");
    if (!std::regex_match(iterations_arg, number_regex))
    {
        throw std::invalid_argument("Invalid iterations value: Must be a positive integer.");
    }

    try
    {
        iterations = std::stoi(iterations_arg);
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid iterations value: Must be an integer.");
    }

    if (iterations <= 0)
    {
        throw std::invalid_argument("Iterations must be a positive integer.");
    }

    return false;
}
bool ParserCommandLine::parse_args_output(int argc, char **argv)
{
    int ind_iter = 0;
    std::string output_arg;

    while ((ind_iter < (argc - 1)) &&
           !((std::string(argv[ind_iter]) == "-o") || (std::string(argv[ind_iter]).substr(0, 9) == "--output=")))
    {
        ++ind_iter;
    }

    if (std::string(argv[ind_iter]) == "-o" && (ind_iter < (argc - 1)))
    {
        output_arg = argv[ind_iter + 1];
    }

    else if (std::string(argv[ind_iter]).substr(0, 9) == "--output=")
    {
        output_arg = std::string(argv[ind_iter]).substr(9);
    }
    else
    {
        return true;
    }

    if (!has_live_extension(output_arg))
    {
        throw std::invalid_argument("Invalid file extension: Output file must have .live extension.");
    }

    output_file = output_arg;
    return false;
}

char ParserCommandLine::get_mode() const
{
    return mode;
}

std::string ParserCommandLine::get_input_file() const
{
    if (mode == '1' || mode == '3')
    {
        return input_file;
    }
    throw std::logic_error("Input file not available in this mode.");
}

std::string ParserCommandLine::get_output_file() const
{
    if (mode == '3')
    {
        return output_file;
    }
    throw std::logic_error("Output file not available in this mode.");
}

int ParserCommandLine::get_iterations() const
{
    if (mode == '3')
    {
        return iterations;
    }
    throw std::logic_error("Iterations not available in this mode.");
}
