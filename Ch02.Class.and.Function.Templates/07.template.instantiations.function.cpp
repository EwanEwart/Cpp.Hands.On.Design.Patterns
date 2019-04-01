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

// template<typename T1, typename T2>
template<typename T2=double, typename T1>
T2 half(T1 const & x) {
  return x/2;
}

int main(int argc, char const *argv[])
{
  // type deduction 101 int
  cout << "1. " << half<double>(101) << endl;
  cout << "1. " << cxx::demangle(typeid(half(101)).name()) << endl;

  // type deduction
  cout << "2. " << half(-100.14) << endl;
  cout << "2. " << cxx::demangle(typeid(half(-100.14)).name()) << endl;

  cout << "3. " << half<unsigned>(100) << endl;
  cout << "3. " << cxx::demangle(typeid(half<unsigned>(100)).name()) << endl;

  cout << "4. " << half<float>(100) << endl;
  cout << "4. " << cxx::demangle(typeid(half<float>(100)).name()) << endl;

  cout << "5. " << half<double>(100.75) << endl;

  return 0;
}
