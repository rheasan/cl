#include <memory>
#include <string>
#include <vector>
#include "./token.hpp"

class Tokenizer {
public:
    Tokenizer(const std::string& input): m_source(input) {}
    std::vector<std::unique_ptr<Token>>& tokenize();
private:
    std::string m_source;
    std::vector<std::unique_ptr<Token>> m_tokens;
    std::size_t m_start = 0;
    std::size_t m_current = 0;
    int m_line = 1;
    bool isAtEnd();
    void scanToken();
    char advance();
    char peek();
    bool match(char expected);
    void addToken(TokenType type);
    void addToken(TokenType type, TokenValue value);
};


