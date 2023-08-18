#include <iostream>
#include <iterator>
#include <array>

/**
 * 与 find_if 相反
 */
namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    if (!_predicate(*first)) {
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
  std::array<int, 5> foo = {1, 2, 3, 4, 5};

  std::array<int, 5>::iterator it;
  it = stdlib::find_if_not(foo.begin(), foo.end(), &is_odd);
  std::cout << "The first even value is " << *it << '\n';
  return 0;
}