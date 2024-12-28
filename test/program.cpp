#include <lexer.hpp>
#include <fstream>
#include <list>

std::string listToString(const std::list<std::string>& lst, const std::string& delimiter = "\n") {
    std::ostringstream oss;
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it != lst.begin()) {
            oss << delimiter;
        }
        oss << *it;
    }
    return oss.str();
}

std::string readfile(std::string name){
    std::ifstream file(name);
    std::list<std::string>* result = new std::list<std::string>();
    
    std::string line;
    while(getline(file, line)){
        result->push_back(line);
    }
    file.close();

    return listToString(*result);
}

int main(){
    Lexer* lexer = new Lexer();
    std::string content = readfile("index.sn");
    std::list<Token>* tokens = lexer->tokenize(content);

    for (Token t : *tokens){
        std::cout << t.type << std::endl;
    }

    std::cout << tokens << std::endl;
}