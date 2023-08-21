#include <iostream>
#include <algorithm>
#include <array>

namespace stdlib {
/**
 * 与 std::none_of 相反
 * @see std::none_of
 */
template<typename InputIterator, typename UnaryPredicate>
bool all_of(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    if (!_predicate(*first)) {
      return false;
    }
    ++first;
  }
  return true;
}
}

/**
 * 自定义一元谓词
 */
bool unary_pred(const int x) {
  return x % 2;
}

int main() {

  std::array<int, 8> foo = {3, 5, 7, 11, 13, 17, 19, 23};

  // Lambda
  if (stdlib::all_of(foo.begin(), foo.end(), [](int i) { return i % 2; })) {
    std::cout << "All the elements are odd numbers.\n";
  }

  if (stdlib::all_of(foo.begin(), foo.end(), &unary_pred)) {
    std::cout << "All the elements are odd numbers.\n";
  }

  return 0;
}