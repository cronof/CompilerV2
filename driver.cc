#include <fstream>
#include <string>
#include <cassert>

#include "driver.hh"
#include "parser.hh"

AnASM::Driver::Driver() :
  file("stdin"),
  loc(new AnASM::location(&file)),
  trace_scanning(false),
  trace_parsing(false)
{ }

AnASM::Driver::~Driver() { }

bool AnASM::Driver::parse()
{
  return parse(file);
}

bool AnASM::Driver::parse(const std::string &f)
{
  std::ifstream in_file(f);

  if (!in_file.good())
  {
    error("Unable to open " + f);
    return false;
  }

  file = f;

  return parse(in_file);
}

bool AnASM::Driver::parse(std::istream &is)
{
  if (!is.good() && is.eof())
    return false;

  delete(lexer);
  delete(parser);

  loc->initialize(&file);

  try
  {
    lexer = new AnASM::Lexer(&is);

    lexer->set_debug(trace_scanning);
  }
  catch (std::bad_alloc &ba)
  {
    error(std::string("Failed to allocate lexer: ") + ba.what());
    exit(EXIT_FAILURE);
  }

  try
  {
    parser = new AnASM::Parser(*this);

    parser->set_debug_level(trace_parsing);
  }
  catch (std::bad_alloc &ba)
  {
    error(std::string("Failed to allocate parser: ") + ba.what());
    exit(EXIT_FAILURE);
  }

  const int accept(0);

  if (parser->parse() != accept)
  {
    error("Syntax error");
    return false;
  }

  return true;
}

void AnASM::Driver::error(const AnASM::location &l, const std::string &m)
{
  std::cerr << l << ": " << m << std::endl;
}

void AnASM::Driver::error(const std::string &m)
{
  std::cerr << m << std::endl;
}
