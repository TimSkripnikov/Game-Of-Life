#include "GameOfLife.hpp"

// Constructor
ParserCommandLine::ParserCommandLine(int argc, char **argv)
    : mode('0'), iterations(0) // Initialize mode and iterations
{
    parse(argc, argv); // Call parse function to process command line arguments
}

// Utility function to validate file extension (checks .live)
bool ParserCommandLine::has_live_extension(const std::string &filename)
{
    const std::string extension = ".live"; // Expected file extension for input/output files
    return filename.size() >= extension.size() &&
           filename.compare(filename.size() - extension.size(), extension.size(), extension) == 0;
}

// Parse command line arguments
void ParserCommandLine::parse(int argc, char **argv)
{
    if (argc == 2) // Case 1: One argument (file input mode)
    {
        input_file = argv[1];                // Assign input file name
        if (!has_live_extension(input_file)) // Validate file extension for input file
        {
            throw std::invalid_argument("Invalid file extension: Input file must have .live extension.");
        }
        mode = '1'; // Set mode to 1 (file input)
    }
    else if (argc == 1) // Case 2: No arguments (random field generation)
    {
        mode = '2'; // Set mode to 2 (random field generation)
    }
    else if (argc >= 4) // Case 3: At least 3 arguments (offline mode with iterations and output)
    {
        input_file = argv[1];
        // Parse iterations and output file arguments
        if (parse_args_iterations(argc, argv) || parse_args_output(argc, argv))
        {
            throw std::invalid_argument("Error parsing arguments!");
        }
        mode = '3'; // Set mode to 3 (offline mode)
    }
    else // Invalid number of arguments
    {
        throw std::invalid_argument("Invalid arguments: Unexpected number of parameters.");
    }
}

// Parse the iterations argument (-i or --iterations)
bool ParserCommandLine::parse_args_iterations(int argc, char **argv)
{
    int ind_iter = 0;
    std::string iterations_arg;

    // Find the argument specifying the number of iterations
    while ((ind_iter < (argc - 1)) &&
           !((std::string(argv[ind_iter]) == "-i") || (std::string(argv[ind_iter]).substr(0, 13) == "--iterations=")))
    {
        ++ind_iter;
    }

    // Handle short option (-i) with the following value
    if (std::string(argv[ind_iter]) == "-i" && (ind_iter < (argc - 1)))
    {
        iterations_arg = argv[ind_iter + 1]; // Get the number of iterations
    }
    // Handle long option (--iterations=value)
    else if (std::string(argv[ind_iter]).substr(0, 13) == "--iterations=")
    {
        iterations_arg = std::string(argv[ind_iter]).substr(13); // Get the number after "--iterations="
    }
    else
    {
        return true; // No iterations argument found
    }

    // Convert iterations to integer and validate
    try
    {
        iterations = std::stoi(iterations_arg); // Convert string to integer
    }
    catch (const std::exception &)
    {
        throw std::invalid_argument("Invalid iterations value: Must be an integer.");
    }

    if (iterations <= 0)
    {
        throw std::invalid_argument("Iterations must be a positive integer.");
    }

    return false; // Successfully parsed iterations
}

// Parse the output file argument (-o or --output=filename)
bool ParserCommandLine::parse_args_output(int argc, char **argv)
{
    int ind_iter = 0;
    std::string output_arg;

    while ((ind_iter < (argc - 1)) &&
           !((std::string(argv[ind_iter]) == "-o") || (std::string(argv[ind_iter]).substr(0, 9) == "--output=")))
    {
        ++ind_iter;
    }

    // Handle short option (-o) with the following value
    if (std::string(argv[ind_iter]) == "-o" && (ind_iter < (argc - 1)))
    {
        output_arg = argv[ind_iter + 1]; // Get the output file name
    }
    // Handle long option (--output=filename)
    else if (std::string(argv[ind_iter]).substr(0, 9) == "--output=")
    {
        output_arg = std::string(argv[ind_iter]).substr(9); // Get the filename after "--output="
    }
    else
    {
        return true; // No output file argument found
    }

    // Validate output file extension
    if (!has_live_extension(output_arg))
    {
        throw std::invalid_argument("Invalid file extension: Output file must have .live extension.");
    }

    output_file = output_arg; // Set the output file
    return false;             // Successfully parsed output file
}

// Getter for mode
char ParserCommandLine::get_mode() const
{
    return mode; // Return the mode (1, 2, or 3)
}

// Getter for input file
std::string ParserCommandLine::get_input_file() const
{
    if (mode == '1' || mode == '3') // Input file is available only in modes 1 and 3
    {
        return input_file;
    }
    throw std::logic_error("Input file not available in this mode.");
}

// Getter for output file
std::string ParserCommandLine::get_output_file() const
{
    if (mode == '3') // Output file is available only in mode 3
    {
        return output_file;
    }
    throw std::logic_error("Output file not available in this mode.");
}

// Getter for iterations
int ParserCommandLine::get_iterations() const
{
    if (mode == '3') // Iterations are available only in mode 3
    {
        return iterations;
    }
    throw std::logic_error("Iterations not available in this mode.");
}
