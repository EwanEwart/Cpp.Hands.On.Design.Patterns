#!/bin/sh

md5=$( (md5 -q || md5sum -b) < $0 2>/dev/null | cut -d ' ' -f1)
script="/tmp/`uuid`"
script="/tmp/$(basename $0).${md5}"
cxx="clang++ -std=c++17 -pipe -Wall"
cxx="g++ -std=c++17 -pipe -Wall"
more_sources=""
linker="-lpthread"
[ -e "${script}" ] || ${cxx} -x c++ -o ${script} - <<INLINE ${more_sources} ${linker} && exec ${script} $@

/*

Non-type template parameters

template template parameters
*/

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <deque>
using std::deque;

template <
  template <typename> class Out_container,
  template <typename> class In_container,
typename T
>
Out_container<T> resequence(In_container<T> const & in_container) {
  Out_container<T> out_container;
  for(auto x:in_container) {
    out_container.push_back(x);
  }
  return out_container;
}

template<typename ... T>
auto prod(T const & ... x) {
  return (x * ...);
}

int main(int argc, char const *argv[])
{

  // vector ---> deque

  vector<int> v {1,2,3,4,5,6,7,8,9,10};

  auto dq(resequence<deque>(v));

  for(auto item:dq){cout << item << ' '; }; cout << endl;

  return 0;
}
