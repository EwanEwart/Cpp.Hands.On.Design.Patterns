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

/*
Defining C++ iterators

https://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
*/

#include <iostream>
using std::cout;
using std::endl;
using std::begin;
using std::end;

#include <typeinfo>
#include "../../demangle.h"

template<typename T, size_t N>
class Array
{
  T data_[N];
public:
  T& operator[](size_t i) {
    if (i>= N)
    {
      throw std::out_of_range("Bad index");
    }
    return data_[i];
  }
  typedef T * iterator;
  typedef T const * const_iterator;
  iterator begin() { return &data_[0];}
  iterator end() { return &data_[N];}
  const_iterator cbegin() const { cout << " c ";return &data_[0];}
  const_iterator cend()   const { cout << " c ";return &data_[N];}
};

int main(int argc, char const *argv[])
{
  int const n(5);

  Array<int,5> a5;

  a5[0] = 0;
  a5[1] = 1;
  a5[2] = 2;
  a5[3] = 3;
  a5[4] = 4;

  // 1. classic loop
  for (int k = 0; k < n; k++)
  {
    cout << a5[k] << ' ';
  }
  cout << endl;

  // 2. member iterator
  for (auto iterator = a5.begin(); iterator != a5.end(); ++iterator ) {
    // cout << cxx::demangle(typeid(iterator).name()) << ' ';
    cout << *iterator << ' ';
  }
  cout << endl;

  // 3. global iterator based on the member iterator
  for (auto iterator(begin(a5)); iterator != end(a5); ++iterator)
  {
    cout << *iterator << ' ';
  }
  cout << endl;

  // 4. range-based for loop: const removed
  for(auto item:a5) {
    cout << item << ' ';
  }
  cout << endl;

  // const interator
  for (auto cit = a5.cbegin(); cit < a5.cend(); ++cit)
  {
    cout << *cit << ' ';
  }
  cout << endl;

  return 0;
}
