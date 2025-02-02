#include "./tokenizer.hpp"
#include <vector>
#include <sstream>

std::vector<Token> Tokenizer::tokenize(const std::string& source) {
    std::vector<Token> result;
    std::stringstream tokens(source);
    std::string segment;
    while(std::getline(tokens, segment, '_'))
    {
       result.push_back(Token {
            .type = TokenType::RETURN,
            .value = segment
        });
    }
    return result;
}
