#include <iostream>
#include <string>
#include <list>
#include <utils.hpp>
#include <type.hpp>

class Lexer
{
    private:
    Utils* utils;
    public:
    Lexer(){
        this->utils = new Utils();
    }
    std::list<Token>* tokenize(std::string code){
        std::list<std::string>* result = this->utils->split(code.data(), " ");
        std::list<Token>* tokens = new std::list<Token>();

        for (std::string& s : *result){
            if (s == "("){
                tokens->push_back(createToken(this->utils->shift(result), Sun_OpenParen));
            } else
            if (s == ")"){
                tokens->push_back(createToken(this->utils->shift(result), Sun_CloseParen));
            } else
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "**"){
                tokens->push_back(createToken(this->utils->shift(result), Sun_MathOperator));
            } else
            if (s == "=") {
                tokens->push_back(createToken(this->utils->shift(result), Sun_Equal));
            } else {
                if (s == "true" || s == "false"){
                    tokens->push_back(createToken(this->utils->shift(result), Sun_Boolean));
                }
            }
        };

        return tokens;
    }
};