#ifndef __LEXER_HH__
#define __LEXER_HH__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.hh"
#include "location.hh"

#undef YY_DECL
#define YY_DECL AnASM::Parser::symbol_type AnASM::Lexer::yylex(AnASM::Driver &driver)

namespace AnASM
{
  class Lexer : public yyFlexLexer
  {
    public:
      Lexer(std::istream *in) : yyFlexLexer(in) { };
      virtual ~Lexer() { };

      virtual AnASM::Parser::symbol_type yylex(AnASM::Driver &driver);
  };
}

#endif
