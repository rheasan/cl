#include "main.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if(argc > 2) {
        std::cerr << "Usage: cpplox [script]" << std::endl;
        return 1;
    }

    CppLox cpplox;

    if(argc == 2) {
        cpplox.runFile(argv[1]);
    } else {
        cpplox.runPrompt();
    }

    return 0;
}
