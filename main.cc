#include <iostream>
#include <cstdlib>
#include <string>
#include "driver.hh"

int main(const int argc, const char **argv)
{
  // TODO: implement user-specified filename argument

  AnASM::Driver driver;

  if (driver.parse(std::cin))
  {
    std::clog << "Success" << std::endl;
    exit(EXIT_SUCCESS);
  }

  exit(EXIT_FAILURE);
}

