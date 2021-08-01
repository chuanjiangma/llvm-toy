#include "Lex/Lexer.h"
#include "Utils/Log.h"

using namespace toy;

static bool CompileEntry(std::string filename) {
  Lexer lexer(filename);
  while (Token t = lexer.GetToken(); t.GetKind() != TokenKind::TK_EOF) {
    Debugf(t.GetStr());
  }

  return true;
}

int main(int argc, const char **argv) {
  std::cout << argc << std::endl;
  if (argc < 2) {
    Errorf("not enough argument, require a file name");
    return 1;
  }

  std::string filename = argv[1];
  if (CompileEntry(filename)) {
    return 1;
  }

  return 0;
}
