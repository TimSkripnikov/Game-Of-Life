#include "GameOfLife.hpp"

// Конструктор
ParserFile::ParserFile(const std::string &file_name) : file_name(file_name) {}

// Метод для парсинга файла
void ParserFile::parse(GameState &game_state)
{
    std::ifstream file(file_name);
    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл");
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue; // Пропустить пустые строки

        if (line.rfind("#Life", 0) == 0)
        {
            // Извлекаем версию игры
            std::string version = line.substr(6); // после "#Life "
            game_state.set_game_version(version);
        }
        else if (line.rfind("#N", 0) == 0)
        {
            // Извлекаем название вселенной
            std::string universe_name = line.substr(3); // после "#N "
            game_state.set_universe_name(universe_name);
        }
        else if (line.rfind("#Size", 0) == 0)
        {
            // Извлекаем размер поля
            int size = std::stoi(line.substr(6)); // после "#Size "
            game_state.set_size(size);
        }
        else if (line.rfind("#R", 0) == 0)
        {
            // Извлекаем условия для клеток
            std::string conditions = line.substr(3); // после "#R "
            parse_conditions(conditions, game_state);
        }
        else
        {
            // Парсим координаты живых клеток
            parse_coordinates(line, game_state);
        }
    }
}

// Метод для парсинга условий B/S
void ParserFile::parse_conditions(const std::string &conditions, GameState &game_state)
{
    std::set<int> B_conditions;
    std::set<int> S_conditions;

    // Пройдемся по строке и разделим на части
    size_t B_pos = conditions.find('B');
    size_t S_pos = conditions.find('S');

    if (B_pos != std::string::npos && S_pos != std::string::npos)
    {
        std::string B = conditions.substr(B_pos + 1, S_pos - B_pos - 1); // Числа между B и S
        std::string S = conditions.substr(S_pos + 1);                    // Числа после S

        parse_condition_set(B, B_conditions);
        parse_condition_set(S, S_conditions);
    }
    else if (B_pos != std::string::npos)
    {
        std::string B = conditions.substr(B_pos + 1); // Все числа после B
        parse_condition_set(B, B_conditions);
    }
    else if (S_pos != std::string::npos)
    {
        std::string S = conditions.substr(S_pos + 1); // Все числа после S
        parse_condition_set(S, S_conditions);
    }
    else
    {
        throw std::runtime_error("Invalid format in conditions string: " + conditions);
    }

    // Устанавливаем условия в объект GameState
    game_state.set_B_conditions(B_conditions);
    game_state.set_S_conditions(S_conditions);
}

// Парсинг строки условий (например, "B3" или "S23")
void ParserFile::parse_condition_set(const std::string &condition_str, std::set<int> &condition_set)
{
    for (char ch : condition_str)
    {
        if (std::isdigit(ch))
        {
            condition_set.insert(ch - '0'); // Преобразуем символ цифры в число
        }
    }
}

// Метод для парсинга координат
void ParserFile::parse_coordinates(const std::string &line, GameState &game_state)
{
    std::istringstream stream(line);
    int row, col;

    // Получаем копию поля из GameState
    Field field = game_state.get_field();

    // Получаем размер поля
    int size = game_state.get_size();
    if (field.size() != size)
    {
        field.resize(size, std::vector<bool>(size, false)); // Инициализируем поле, если нужно
    }

    while (stream >> row >> col)
    {
        // Поскольку координаты в файле начинаются с 1, а в массиве с 0,
        // нужно уменьшить на 1.
        field[row - 1][col - 1] = true; // Живая клетка
    }

    // Обновляем поле в объекте GameState
    game_state.set_field(field);
}
