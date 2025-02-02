#include <string>
#include <vector>
#include "./token.hpp"

class Tokenizer {
public:
    Tokenizer() {}
    std::vector<Token> tokenize(const std::string& source);
};


