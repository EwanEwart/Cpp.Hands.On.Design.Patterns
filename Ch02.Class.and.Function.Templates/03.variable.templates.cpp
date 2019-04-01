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

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::acos;

/*
Third type of C++ template: Variable template
*/
template<typename T>
constexpr T pi = T(acos(-1.L));
// constexpr T pi = T(3.14159265358979323846264338327950288419716939937510582097494459230781L);
//                    3.14159265358979323851280895940618620443274267017841339111328125
//                    3.141592653589793239
int main(int argc, char const *argv[])
{

  cout << " 1. " << pi<int> << endl;
  cout << " 2. " << pi<float> << endl;
  cout << " 3. " << setprecision(68) << pi<long double> << endl;
  cout << " 4. " << setprecision(std::numeric_limits<long double>::digits10) << pi<long double> << endl;
  cout << " 5. " << setprecision(std::numeric_limits<long double>::max_digits10) << pi<long double> << endl;
  cout << " 6. " << std::numeric_limits<long double>::digits10 << endl;
  cout << " 7. " << std::numeric_limits<long double>::max_digits10 << endl;
  cout << " 8. " << std::numeric_limits<long double>::max() << endl;
  cout << " 9. " << acos(-1.L) << endl;
  return 0;
}
