#!/bin/sh

md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
script="/tmp/`uuid`"
script="/tmp/$(basename $0).${md5}"
cxx="clang++ -std=c++11 -pipe -Wall"
cxx="g++ -std=c++17 -pipe -Wall"
more_sources=""
linker="-lpthread"
[ -e "${script}" ] || ${cxx} -x c++ -o ${script} - <<INLINE ${more_sources} ${linker} && exec ${script} $@

#include <iostream>
using std::cout;
using std::endl;

#include "../../demangle.h"

template<typename T>
auto half(T const & x) {
  return x/2;
}

int main(int argc, char const *argv[])
{
  // type deduction
  cout << "1. " << half(100) << endl;
  cout << "1. " << cxx::demangle(typeid(half(100)).name()) << endl;

  // type deduction
  cout << "2. " << half(-100.14) << endl;
  cout << "2. " << cxx::demangle(typeid(half(-100.14)).name()) << endl;

  cout << "4. " << half<unsigned>(100) << endl;
  cout << "4. " << cxx::demangle(typeid(half<unsigned>(100)).name()) << endl;

  cout << "5. " << half<float>(100) << endl;
  cout << "5. " << cxx::demangle(typeid(half<float>(100)).name()) << endl;

  cout << "6. " << half<double>(100.75) << endl;

  long x = ...;

  return 0;
}
