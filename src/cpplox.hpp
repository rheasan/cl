#include <string>
#include "./tokenizer.hpp"

class CppLox {
public:
    CppLox() {}
    void runPrompt();
    void runFile(const std::string& fileName);
private:
    void run(const std::string& source);
    void error(int line, std::string message);
    void report(int line, std::string where, std::string message);
    Tokenizer tokenizer;
    bool hasError = false;
};