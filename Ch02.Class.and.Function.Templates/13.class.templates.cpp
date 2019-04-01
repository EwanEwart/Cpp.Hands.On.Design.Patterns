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

template<typename N,typename D>
class Ratio {
  N num_;
  D denom_;
public:
  Ratio()
  // : num_()
  // , denom_()
  : num_(0)
  , denom_(1)
  {
    cout << "num_   == " << num_   << endl;
    cout << "denom_ == " << denom_ << endl;
  }

  Ratio(N const & num, D const & denom)
  : num_(num)
  , denom_(denom)
  {
    cout << "num_   == " << num_   << endl;
    cout << "denom_ == " << denom_ << endl;
  }

  operator double() const {
  // explicit operator double() const {
    return double(num_) / double(denom_);
  }

};

template<typename N, typename D>
Ratio<N,D> make_ratio(N const & num, D const & denom) {
  return { num,denom};
}

int main(int argc, char const *argv[])
{
  auto n4711_11(Ratio(4711.5577,11));
  auto n4711_7(Ratio(4711,7.0f));

  Ratio<int,double> r1;
  Ratio<int,double> r2(4711,7.25F);

  auto r3(make_ratio(7.15,2));

  Ratio r4(7.15,2);

  cout << " 1 -> " << double(n4711_11) << endl;
  cout << " 2 -> " << double(n4711_7) << endl;
  cout << " 3 -> " << r1 << endl;
  cout << " 4 -> " << r2 << endl;
  cout << " 5 -> " << r3 << endl;
  cout << " 6 -> " << r4 << endl;


  return 0;
}
