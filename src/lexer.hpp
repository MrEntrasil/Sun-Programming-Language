#include <iostream>
#include <string>
#include <vector>
#pragma once

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

class Lexer
{
public:
    std::vector<Token> tokenize(const std::string src)
    {
        std::vector<Token> tokens;
        std::string buff;

        for (int i = 0;i < src.length();i++)
        {
            char c = src.at(i);
            if (std::isspace(c))
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
                while (std::isalnum(src.at(i)))
                {
                    buff.push_back(src.at(i));
                    i++;
                }
                i--;

                if (buff == "return")
                {
                    tokens.push_back({ .type = TokenType::Return });
                }
                else
                {
                    std::cout << "Unknown token: " << c << std::endl;
                    exit(EXIT_FAILURE);
                }
                buff.clear();
                continue;
            } else if (c == ';')
            {
                tokens.push_back({ .type = TokenType::Sep });
                buff.clear();
                i++;
                continue;
            } else
            {
                std::cout << "Unknown token: " << c << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        return tokens;
    };
};