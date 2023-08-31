#include <iostream>
#include <algorithm>
#include <array>

namespace stdlib {
/**
 * 判断迭代器 InputIterator 元素是否都满足 UnaryPredicate 条件
 *
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
 * @param x 是不是奇数
 */
bool is_odd(const int x) {
  return x % 2;
}

int main() {

  std::array<int, 8> foo = {3, 5, 7, 11, 13, 17, 19, 23};

  // Lambda
  if (stdlib::all_of(foo.begin(), foo.end(), [](int i) { return i % 2; })) {
    std::cout << "All the elements are odd numbers.\n";
  }

  if (stdlib::all_of(foo.begin(), foo.end(), is_odd)) {
    std::cout << "All the elements are odd numbers.\n";
  }

  return 0;
}