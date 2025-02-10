#include <optional>
#include <string>
#include <variant>
enum class TokenType {
    // single character token
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // one or two char tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    
    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    _EOF
};

typedef std::optional<std::variant<int, char, std::string>> TokenValue;

struct Token {
    const TokenType type;
    const std::string name;
    const TokenValue value;
    const int line;
    Token(TokenType type, std::string name, TokenValue value, int line)
        : type(type), name(name), value(value), line(line) {}
};
