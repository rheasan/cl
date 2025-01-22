#include "cpplox.hpp"
#include <iostream>

void CppLox::runFile(std::string fileName) {
    std::cout << "In runfile: filename = " << fileName << std::endl;
}

void CppLox::runPrompt() {
    std::cout << "In runPrompt" << std::endl;
}