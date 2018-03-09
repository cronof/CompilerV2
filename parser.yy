%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define api.namespace {AnASM}
%define parser_class_name {Parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires
{
#include <iostream>
#include <string>

namespace AnASM
{
  class Driver;
  class Lexer;
}
}

%parse-param { AnASM::Lexer &lexer }
%param { AnASM::Driver &driver }

%locations

%initial-action
{
  // @$.begin.filename = @$.end.filename = &driver.file;
};

%define parse.trace
%define parse.error verbose

%code
{
#include "driver.hh"
#include "lexer.hh"

#undef yylex
#define yylex lexer.yylex
}

%define api.token.prefix {TOK_}

%token
  END 0 "end of file"
  NEWLINE "new line"
  COMMA "comma"
  COLON "colon"
  LOAD  "LOAD"
  ADD   "ADD"
  SUB   "SUB"
  OR    "OR"
  XOR   "XOR"
  BRA   "BRA"
  BRAZ  "BRAZ"
  BRAL  "BRAL"
  BRALZ "BRALZ"
  CALL  "CALL"
  IN    "IN"
  OUT   "OUT"
  HALT  "HALT"

%token <int> REGISTER "register"
%token <int> INTEGER "integer"
%token <std::string> IDENTIFIER "identifier"

%type <std::vector<instruction> > program

%type <variant> statements
%type <variant> statement


%printer { yyoutput << $$; } <*>;

%%
%start program;

program: END            { driver.program = std::vector<instruction>(0); }
       | statements END { driver.program.insert($1); }
       ;

statements: statement
          | statements statement
          ;

statement: LOAD REGISTER COMMA INTEGER {
                 std::cout << driver.program = vector<instruction>($2) << driver.program = vector<instruction>($4) << std::endl; }
          | ADD REGISTER COMMA REGISTER COMMA REGISTER {
                 std::cout << driver.program = vector<instruction>($2)
                 << driver.program = vector<instruction>($4) << driver.program = vector<instruction>($6) << std::endl; }
          | SUB REGISTER COMMA REGISTER COMMA REGISTER {
                 std::cout << driver.program = vector<instruction>($2)
                 << driver.program = vector<instruction>($4) << driver.program = vector<instruction>($6) << std::endl; }
          | OR REGISTER COMMA REGISTER COMMA REGISTER {
                 std::cout << driver.program = vector<instruction>($2)
                 << driver.program = vector<instruction>($4) << driver.program = vector<instruction>($6) << std::endl; }
          | XOR REGISTER COMMA REGISTER COMMA REGISTER {
                 std::cout << driver.program = vector<instruction>($2)
                 << driver.program = vector<instruction>($4) << driver.program = vector<instruction>($6) << std::endl; }
          | BRA REGISTER {
                 std::cout << driver.program = vector<instruction>($2) << std::endl; }
          | BRAZ REGISTER COMMA REGISTER {
                 std::cout << driver.program = vector<instruction>($2) << driver.program = vector<instruction>($4) << std::endl; }
          | BRAL IDENTIFIER{}
          | BRALZ REGISTER COMMA INTEGER {
                 std::cout << driver.program = vector<instruction>($2) << driver.program = vector<instruction>($4) << std::endl; }
          | BRALZ REGISTER COMMA IDENTIFIER {
                 std::cout << driver.program = vector<instruction>($2) << std::endl; }
          | CALL REGISTER COMMA INTEGER {
                 std::cout << driver.program = vector<instruction>($2) << driver.program = vector<instruction>($4) << std::endl; }
          | CALL REGISTER COMMA IDENTIFIER {
                 std::cout << driver.program = vector<instruction>($2) << std::endl; }
          | IN REGISTER {
                 std::cout << driver.program = vector<instruction>($2) << std::endl; }
          | OUT REGISTER {
                 std::cout << driver.program = vector<instruction>($2) << std::endl; }
          | HALT { std::cout << driver.program = vector<instruction>(0) << std::endl; }
          | IDENTIFIER COLON{}
          | NEWLINE
          ;

%%

void AnASM::Parser::error(const location_type &l, const std::string &m)
{
  driver.error(l, m);
}
