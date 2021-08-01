#ifndef _TOYC_LEX_LEXER_H
#define _TOYC_LEX_LEXER_H
#include <string>

namespace toy {
class Token {
public:
  Token();
  Token(std::string str, TokenKind kind) : str(str), kind(kind) {}
  ~Token() {}
  std::string GetStr() const;
  TokenKind GetKind() const;

private:
  std::string str;
  TokenKind kind;
};

enum TokenKind {
#define TOKEN(tok_id, tok_str) TK_##tok_id,
#include "Lex/TokensDef.inc"
#undef TOKEN
};

class Lexer {
public:
  Lexer(const char *file, unsigned size) : file(file), size(size) {}
  Lexer(const std::string filename) {}
  Token GetToken() const;
  ~Lexer() {}

private:
  const char *file = nullptr;
  const unsigned size = 0;
  unsigned int offset = 0;
};
} // namespace toy

#endif

