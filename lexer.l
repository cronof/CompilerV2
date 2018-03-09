%{
#include <cstdlib>
#include <string>
#include "driver.hh"
#include "parser.hh"
#include "lexer.hh"

#define YY_NO_UNISTD_H

#undef YY_DECL
#define YY_DECL AnASM::Parser::symbol_type AnASM::Lexer::yylex(AnASM::Driver &driver)

#undef yywrap
#define yywrap() 1

#define loc driver.loc
%}

%option yyclass="AnASM::Lexer"
%option c++
%option noyywrap nounput batch debug noinput yylineno

%{
  #define YY_USER_ACTION loc->columns(yyleng);
%}

delimiter  [ \t]
whitespace {delimiter}+
digit      [0-9]
alpha      [a-zA-Z]
alphanum   [a-zA-Z0-9]
integer    [-]?{digit}+
register   [rR]{digit}+
identifier [a-zA-Z_][a-zA-Z0-9_]*

%%
%{
  loc->step();
%}

{register}  {
    int rn = atoi(yytext + 1);
    if ((rn >= 0) && (rn <= 15))
      return AnASM::Parser::make_REGISTER(rn, *loc);
    else
    {
      driver.error(*loc, std::string("unknown register R") + std::to_string(rn));
      exit(EXIT_FAILURE);
    }
  }

{integer}   {
    int n = atoi(yytext);
    if ((n >= -127) && (n <= 128))
      return AnASM::Parser::make_INTEGER(atoi(yytext), *loc);
    else
    {
      driver.error(*loc, std::string("out of 8-bit signed integer range"));
      exit(EXIT_FAILURE);
    }
  }

,         { return AnASM::Parser::make_COMMA(*loc); }
:         { return AnASM::Parser::make_COLON(*loc); }

"LOAD"    { return AnASM::Parser::make_LOAD(*loc); }
"ADD"     { return AnASM::Parser::make_ADD(*loc); }
"SUB"     { return AnASM::Parser::make_SUB(*loc); }
"OR"      { return AnASM::Parser::make_OR(*loc); }
"XOR"     { return AnASM::Parser::make_XOR(*loc); }
"BRA"     { return AnASM::Parser::make_BRA(*loc); }
"BRAZ"    { return AnASM::Parser::make_BRAZ(*loc); }
"BRAL"    { return AnASM::Parser::make_BRAL(*loc); }
"BRALZ"   { return AnASM::Parser::make_BRALZ(*loc); }
"CALL"    { return AnASM::Parser::make_CALL(*loc); }
"IN"      { return AnASM::Parser::make_IN(*loc); }
"OUT"     { return AnASM::Parser::make_OUT(*loc); }
"HALT"    { return AnASM::Parser::make_HALT(*loc); }
<<EOF>>   { return AnASM::Parser::make_END(*loc); }

{identifier} { return AnASM::Parser::make_IDENTIFIER(yytext, *loc); }

{whitespace} { loc->step(); }
\n           { loc->lines(yyleng); loc->step(); return AnASM::Parser::make_NEWLINE(*loc); }

.         { driver.error(*loc, std::string("unknown token ``") + yytext + "''"); exit(EXIT_FAILURE); }

%%
