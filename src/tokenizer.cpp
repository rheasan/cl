#include "./tokenizer.hpp"
#include <optional>
#include <vector>
#include "./cpplox.hpp"

std::vector<std::unique_ptr<Token>>& Tokenizer::tokenize() {
   while(!isAtEnd()) {
      m_start = m_current;
      scanToken();
   }

   m_tokens.push_back(std::make_unique<Token>(TokenType::_EOF, "",  std::nullopt, m_line));

   return m_tokens;
}

bool Tokenizer::isAtEnd() {
   return m_current >= m_source.size();
}

/**
 * Read and consume the next character from m_source
 */
char Tokenizer::advance() {
   return m_source[m_current++];
}

/**
 * Read but not consume the next character from m_source
 */
char Tokenizer::peek() {
   if(isAtEnd()) return '\0';
   return m_source[m_current];
}

void Tokenizer::addToken(TokenType type) {
   addToken(type, std::nullopt);
}

void Tokenizer::addToken(TokenType type, TokenValue value) {
   std::string name = m_source.substr(m_start, m_current - m_start);
   m_tokens.push_back(std::make_unique<Token>(type, name, value, m_line));
}

void Tokenizer::scanToken() {
   char next = advance();

   switch (next) {
   // check for single character token - '/' is not included because it can be a comment
      case '(': {
         addToken(TokenType::LEFT_PAREN);
         break;
      }
      case ')': {
         addToken(TokenType::RIGHT_PAREN);
         break;
      }
      case '{': {
         addToken(TokenType::LEFT_BRACE);
         break;
      }
      case '}': {
         addToken(TokenType::RIGHT_BRACE);
         break;
      }
      case ',': {
         addToken(TokenType::COMMA);
         break;
      }
      case '.': {
         addToken(TokenType::DOT);
         break;
      }
      case '-': {
         addToken(TokenType::MINUS);
         break;
      }
      case '+': {
         addToken(TokenType::PLUS);
         break;
      }
      case ';': {
         addToken(TokenType::SEMICOLON);
         break;
      }
      case '*': {
         addToken(TokenType::STAR);
         break;
      }
      // check for one or two char tokens
      case '!': {
         addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
         break;
      }
      case '=': {
         addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
         break;
      }
      case '>': {
         addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
         break;
      }
      case '<': {
         addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
         break;
      }

      // check for division or comment
      case '/': {
         if(match('/')) {
            // discard all tokens until the newline
            while(!isAtEnd() && peek() != '\n') advance();
         } else {
            addToken(TokenType::SLASH);
         }
         break;
      }

      // ignore whitespace
      case ' ':
      case '\r':
      case '\t': {
         break;
      }

      case '\n': {
         m_line++;
         break;
      }
      default: {
         CppLox::error(m_line, "Unexpected character");
         break;
      }
   }

}


/**
* Consume the next character if it is equal to expected character
*/
bool Tokenizer::match(char expected) {
   if(isAtEnd()) return false;
   if(m_source[m_current] != expected) return false;

   m_current++;
   return true;
}
