#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "lexer.hpp"

std::string readFile(std::string path)
{
    std::ostringstream oss;
    std::ifstream file(path, std::ios::in);
    std::string buff;
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        std::cout << "Check file dir." << std::endl;
        exit(EXIT_FAILURE);
    }
    oss << file.rdbuf();
    file.close();

    return oss.str();
};

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        std::cout << "Incorret usage" << std::endl;
        std::cout << "Correct usage: SunPL [flags] [options]" << std::endl;
        return EXIT_FAILURE;
    }
    std::string content = readFile(argv[1]);
    Lexer* lexer = new Lexer();
    std::vector<Token> tokens = lexer->tokenize(content);
    std::cout << tokens.size() << std::endl;

    return EXIT_SUCCESS;
};