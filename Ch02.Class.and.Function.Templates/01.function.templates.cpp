// #!/bin/sh

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

template <typename T>
auto increment(T t)
{
  return ++t;
}
template <typename T>
auto decrement(T t)
{
  return --t;
}

template <typename T>
auto sum(T const &from, T const &to, T const &inc = 1)
{
  T total(0);
  for (auto k(from); k <= to; k += inc)
  {
    total += k;
  }
  return total;
}

auto main(int argc, char const *argv[]) -> int
{
  auto n(1000);
  auto d(1.17);
  auto c('a');

  cout << "n : " << n << endl;
  cout << "n++ : " << increment(n) << endl;

  cout << "d : " << d << endl;
  cout << "d++ : " << increment(d) << endl;

  cout << "c : " << '\'' << c << '\'' << endl;
  cout << "c++ : " << '\'' << increment(c) << '\'' << endl;

  cout << "-------------" << endl;
  cout << sum(1, 100) << endl;
  cout << sum(1.0, 100.0, 0.5) << endl;
  cout << sum('a', 'e', '0') << endl;

  return 0;
}

/*
Ctrl+Shift+B

C/C++: clang++-6.0 build active file
-rwxrwxr-x 1 ewan ewan 29264 Mar 13 10:23 01.function.templates*

C/C++: c++ build active file
-rw-rw-r-- 1 ewan ewan 666745 Mar 13 10:25 01.function.templates

C/C++: g++ build active file
-rwxrwxr-x 1 ewan ewan 35512 Mar 13 10:35 01.function.templates*

C/C++: g++-7 build active file
-rwxrwxr-x 1 ewan ewan 35512 Mar 13 10:38 01.function.templates*

*/
