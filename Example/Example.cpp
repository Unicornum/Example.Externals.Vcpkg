
#include <iostream>
#include <boost\predef\compiler.h>
#include <boost\filesystem.hpp>

#if BOOST_COMP_MSVC

# ifdef _DEBUG
#   pragma comment(lib, "boost_filesystem-vc142-mt-gd-x64-1_86.lib")
# else
#   pragma comment(lib, "boost_filesystem-vc142-mt-x64-1_86.lib")
# endif

#endif


int main(int /*_Argc*/, char * /*_Argv*/[])
{
  ::boost::filesystem::path PathToHell = "";
  ::std::cout << PathToHell.c_str() << ::std::endl;

  return 0;
}
