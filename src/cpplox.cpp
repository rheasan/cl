#include "cpplox.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "tokenizer.hpp"

bool CppLox::s_hasError = false;

void CppLox::runFile(const std::string& fileName) {
    std::ifstream f(fileName);
    std::stringstream ss;
    ss << f.rdbuf();

    this->m_source = ss.str();
    this->run(m_source);
    
    f.close();
}

void CppLox::runPrompt() {
//     for(std::string line; std::getline(std::cin, line);) {
//         if(line == "") {
//             return;
//         }
//         this->run(line);
//         if(m_hasError) exit(101);
//     }
}

void CppLox::run(const std::string& source) {
    Tokenizer tokenizer(source);
    for(const auto& token: tokenizer.tokenize()) {
    }
}

void CppLox::error(int line, std::string message) {
    report(line, "", message);
}

void CppLox::report(int line, std::string where, std::string message) {
    std::cerr << "[ line " << line << " ] Error " << where << ": " << message << std::endl;
    s_hasError = true;
}
