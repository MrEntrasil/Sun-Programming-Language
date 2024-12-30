#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

enum class TokenType
{
    Number,
    Return,
    Sep
};

struct Token
{
    TokenType type;
    std::string value = "";
};

std::vector<Token> tokenize(std::string src)
{
    std::vector<Token> tokens;
    std::string buff;

    for (int i = 0;i < src.length();i++)
    {
        char c = src.at(i);
        if (std::isblank(c))
        {
            continue;
        }
        else if (std::isdigit(c))
        {
            buff.push_back(c);
            i++;
            while (std::isdigit(src.at(i)))
            {
                buff.push_back(src.at(i));
                i++;
            }
            i--;

            tokens.push_back({ .type = TokenType::Number, .value = buff });
            buff.clear();
        } else if (std::isalpha(c))
        {
            buff.push_back(c);
            i++;
            while (std::isalpha(src.at(i)))
            {
                buff.push_back(src.at(i));
                i++;
            }
            i--;

            if (buff == "return")
            {
                tokens.push_back({ .type = TokenType::Return });
            } else {
                std::cout << "Unknown token: " << c << std::endl;
                exit(EXIT_FAILURE);
            }
            buff.clear();
            continue;
        } else if (c == ';')
        {
            tokens.push_back({ .type = TokenType::Sep });
        } else
        {
            std::cout << "Unknown token: " << c << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
};

std::string readFile(std::string path)
{
    std::ostringstream oss;
    std::ifstream file(path, std::ios::in);
    std::string buff;
    oss << file.rdbuf();

    return oss.str();
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Incorret usage" << std::endl;
        std::cout << "Correct usage: SunPL <path/to/file>.sn" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string content = readFile(argv[1]);
    std::vector<Token> tokens = tokenize(content);

    std::cout << tokens.size() << std::endl;

    return EXIT_SUCCESS;
};