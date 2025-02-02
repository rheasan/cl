#include <string>
#include "./tokenizer.hpp"

class CppLox {
public:
    CppLox() {}
    void runPrompt();
    void runFile(std::string fileName);
private:
    void run(const std::string& source);
    Tokenizer tokenizer;
};