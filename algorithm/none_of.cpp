#include <array>
#include <iostream>

/**
 * 判断迭代器 InputIterator 元素是否都不满足 UnaryPredicate 条件(与 std::all_of 相反).
 *
 * @see std::all_of
 */

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    if (_predicate(*first)) {
      return false;
    }
    ++first;
  }
  return true;
}
}  // namespace stdlib

bool less_zero(int v) {
  return v < 0;
}

int main() {
  std::array<int, 8> foo = {1, 2, 3, 4, 16, 32, 64, 128};
  if (stdlib::none_of(foo.begin(), foo.end(), &less_zero)) {
    std::cout << "There are no negative elements in the ranges." << '\n';
  }

  return 0;
}