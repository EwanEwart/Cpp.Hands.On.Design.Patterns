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

#include <ostream>
using std::ostream;

#include <utility>
using std::pair;
using std::make_pair;

#include "../../demangle.h"

template<typename U, typename V>
ostream& operator<<(ostream & os, pair<U,V> const & p) {
  os << "( " << p.first << ", " << p.second << ")";
  return os;
}

template<typename U, typename V>
auto swap12(pair<U,V> const & p) {
  return make_pair(p.second,p.first);
  // return pair<V,U>(p.second,p.first);
}

int main(int argc, char const *argv[])
{
  // auto p = make_pair(2.125,1);

  // cout << p << endl;
  cout << swap12(make_pair(2.125,1)) << endl;
  // cout << swap12(p) << endl;

  return 0;
}
