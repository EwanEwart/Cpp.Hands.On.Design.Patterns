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
using std::cerr;
using std::endl;

template<typename T>
class ArrayOf2
{
  T a_[2];
public:
  T const& operator[](size_t i) const {
    cerr << "T const ref" << endl;
    return a_[i];
  }
  T & operator[](size_t i) {
    cerr << "T ref" << endl;
    return a_[i];
  }
  T sum() { return a_[0] + a_[1];}
};

int main(int argc, char const *argv[])
{
  cout << "----------------------" << endl;
  ArrayOf2<int> ao2;
  ao2[0] = 11; // T & operator[](size_t i)
  ao2[1] = -22;// T & operator[](size_t i)
  cout << ao2.sum() << endl;

  cout << "----------------------" << endl;
  ArrayOf2<double> ao2d;
  ao2d[0] = 11.11; // T & operator[](size_t i)
  ao2d[1] = -22.22;// T & operator[](size_t i)
  cout << ao2d.sum() << endl;

  cout << "----------------------" << endl;
  cout << ao2d[0] << endl;
  cout << ao2d[1] << endl;

  return 0;
}
