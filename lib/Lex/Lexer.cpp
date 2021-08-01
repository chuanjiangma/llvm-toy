#include "Lex/Token.h"

#include <string>
#include <unordered_map>

using namespace toy;

namespace {
std::unordered_map<TokenKind, std::string> Tokens({
#define TOKEN(tok_id, tok_str) {TokenKind::TK_##tok_id, tok_str},
#include "Lex/TokensDef.inc"
#undef TOKEN
});

Token::Token() {
  str = "";
  kind = TokenKind::TK_INVALID;
}

std::string Token::GetStr() const { return str; }

TokenKind Token::GetKind() const { return kind; }


}; // namespace

