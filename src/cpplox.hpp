#include <string>
#include "./tokenizer.hpp"

class CppLox {
public:
    CppLox() {}
    void runPrompt();
    void runFile(const std::string& fileName);
private:
    void run(const std::string& source);
    Tokenizer tokenizer;
};