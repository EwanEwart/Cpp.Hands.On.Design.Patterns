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

/*
In C++14, as well as in C++17,
when a ---fold expression--- is not sufficient,
*** and they are useful only in limited contexts,
mostly when the arguments and combines
using binary or unary operators ***
the standard technique is recursion,
which is ever-popular in template programming
*/

template<typename T>
auto sum(T t1) {
  return t1;
}

template<typename T1,typename ... T>        // possibly of different types
auto sum(T1 const& t1, T const& ... t) {    // one or more arguments
  return t1 + sum(t ...);
}

auto main(int argc, char const *argv[]) -> int
{
  cout << sum(
    1,2,3,4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,18,19,20,
    21,22,23,24,25,26,27,28,29,30,
    31,32,33,34,35,36,37,38,39,40,
    41,42,43,44,45,46,47,48,49,50
  ) << endl;

  return 0;
}
