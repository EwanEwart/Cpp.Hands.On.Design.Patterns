// #!/bin/sh
// 
// md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
// script="/tmp/`uuid`"
// script="/tmp/$(basename $0).${md5}"
// cxx="clang++ -std=c++17 -pipe -Wall"
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

#include <tuple>
#include <bitset>

#include "../../demangle.h"

template<typename U, typename V>
ostream& operator<<(ostream & os, std::pair<U,V> const & p) {
  cout << "( " << p.first << ", " << p.second << ")";
  return os;
}

// variadic template
template<typename ... T>
ostream& operator<<(ostream & os, std::tuple<T...> const & t) {
  // // Another C++17 feature: class template argument deduction
  // std::tuple t1 {42, 'a', 4.2, "Kate"};
  // auto t2 = std::make_tuple("Ewan", 3.1415F, 'b', 4.2, 2.17f, std::bitset<16>(4711));
  // cout << t1 << endl;
  // cout << t2 << endl;
  os << "( ";
  std::apply([&os](auto&&... args) {((os << args << "  "), ...); } , t );
  os << ")";
  return os;
}

// second version
template<typename T>
auto swap12(T const & p) {
  return std::make_pair(p.second,p.first);
  // return std::pair<V,U>(p.second,p.first);
}

int main(int argc, char const *argv[])
{
  auto p = std::make_pair(2.125,1);

  // cout << p << endl;
  cout << swap12(std::make_pair(2.125,1)) << endl;
  cout << swap12(p) << endl;

  // Another C++17 feature: class template argument deduction
  std::tuple t1 {42, 'a', 4.2, "Kate"};
  auto t2 = std::make_tuple("Ewan", 3.1415F, 'b', 4.2, 2.17f, std::bitset<16>(4711));
  cout << t1 << endl;
  cout << t2 << endl;

  return 0;
}
