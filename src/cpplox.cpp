#include "cpplox.hpp"
#include <iostream>

void CppLox::runFile(std::string fileName) {
    std::cout << "In runfile: filename = " << fileName << std::endl;
}

void CppLox::runPrompt() {
    for(std::string line; std::getline(std::cin, line);) {
        this->run(line);
    }
}

void CppLox::run(const std::string& source) {
    std::vector<Token> tokens = this->tokenizer.tokenize(source);
    for(Token token: tokens) {
        std::cout << "token: " << token.toString() << std::endl;
    }
}
