#include <iostream>
#include <iterator>
#include <vector>

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    if (_predicate(*first)) {
      return first;
    }
    ++first;
  }
  return last;
}
}

bool is_odd(int i) {
  return (i % 2);
}

int main() {
  std::vector<int> vt;

  vt.push_back(10);
  vt.push_back(25);
  vt.push_back(40);
  vt.push_back(55);

  std::vector<int>::iterator it;
  it = stdlib::find_if(vt.begin(), vt.end(), &is_odd);
  std::cout << "The first odd value is " << *it << '\n';
  return 0;
}