#include <string>
#include <sstream>
enum class TokenType {
    RETURN = 1,
};

struct Token {
    TokenType type;
    // TODO: value shouldn't be a string
    std::string value;

    std::string toString() {
        std::stringstream s;
        s << "type: ";
        switch(this->type) {
            case TokenType::RETURN:
                s << "return";
                break;
        }
        s << " value: " << this->value;

        return s.str();
    }
};
