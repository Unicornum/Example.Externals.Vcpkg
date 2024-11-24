
#include <iostream>
#include <boost\predef\compiler.h>
#include <boost\filesystem.hpp>

int main(int /*_Argc*/, char * /*_Argv*/[])
{
  ::boost::filesystem::path PathToHell = "";
  ::std::cout << PathToHell.c_str() << ::std::endl;

  return 0;
}
