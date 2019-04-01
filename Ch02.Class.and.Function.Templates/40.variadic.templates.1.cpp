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

template<typename ... T>    // possibly of different types
auto sum(T const & ... x) { // one or more arguments
  return(x + ...);          // C++17 has fold expressions
}

template<typename ... T>
auto prod(T const & ... x) {
  return(x * ...);
}

int main(int argc, char const *argv[])
{
  cout << sum(1,2,3,4,5,6,7,8,9,10) << endl;
  cout << sum(1,2L,3,4L,5,6L,7,8L,9,10L) << endl;
  cout << sum(1.5,2L,3.7,4L,5,6L,7,8L,9,10L) << endl;

  cout << prod(1.1,2.2,3.3,4.4,5.5,6.6) << endl;

  return 0;
}
