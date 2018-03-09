#ifndef __ANASM_DRIVER_HH__
#define __ANASM_DRIVER_HH__

#include <string>
#include "parser.hh"
#include "lexer.hh"

namespace AnASM
{
  class Driver
  {
    public:
      Driver();
      virtual ~Driver();

      bool trace_scanning;
      bool trace_parsing;

      bool parse(const std::string &f);
      bool parse(std::istream &is);

      void error(const AnASM::location &l, const std::string &m);
      void error(const std::string &m);

    private:
      std::string file;
      AnASM::Parser *parser = nullptr;
      AnASM::Lexer  *lexer  = nullptr;
      AnASM::location *loc;

      const std::string red    = "\033[1;31m";
      const std::string blue   = "\033[1;36m";
      const std::string normal = "\033[0m";

      std::string file;

      friend class Lexer;
      friend class Parser;
  };
}

#endif
