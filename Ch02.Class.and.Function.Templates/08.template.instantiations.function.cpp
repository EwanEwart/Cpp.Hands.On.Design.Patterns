// #!/bin/sh
//
// md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
// script="/tmp/`uuid`"
// script="/tmp/$(basename $0).${md5}"
// cxx="clang++ -std=c++11 -pipe -Wall"
// cxx="g++ -std=c++17 -pipe -Wall"
// more_sources=""
// linker="-lpthread"
// [ -e "${script}" ] || ${cxx} -x c++ -o ${script} - <<INLINE ${more_sources} ${linker} && exec ${script} $@

#include <iostream>
using std::cout;
using std::endl;

#include "../../demangle.h"

template <typename T>
T Max(T x, T y) { return (x > y) ? x : y; }

int main(int argc, char const *argv[])
{
  auto a {7L};
  auto b {11L};

  auto m = Max(a, b);

  cout << "Max ( " << a << ", " << b << ") == " << m << endl;


  return 0;
}
