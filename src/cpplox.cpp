#include "cpplox.hpp"
#include <iostream>
#include <fstream>

void CppLox::runFile(const std::string& fileName) {
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();
    this->run(ss.str());
    f.close();
}

void CppLox::runPrompt() {
    for(std::string line; std::getline(std::cin, line);) {
        if(line == "") {
            return;
        }
        this->run(line);
    }
}

void CppLox::run(const std::string& source) {
    std::vector<Token> tokens = this->tokenizer.tokenize(source);
    for(Token token: tokens) {
        std::cout << "token: " << token.toString() << std::endl;
    }
}
