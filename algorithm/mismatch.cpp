#include <iostream>
#include <utility>
#include <vector>

/**
 * 将范围 [first1,last1) 中的元素与从 first2 开始的范围中的元素进行比较，并返回两个序列中不匹配的第一个元素.
 * <br>
 * 该函数返回 std::pair<InputIterator1, InputIterator2>，指向每个范围中不匹配的第一个元素. 如果 InputIterator1
 * 为 last1, 说明都匹配.
 */

namespace stdlib {
/**
 * version 1
 */
template<typename InputIterator1, typename InputIterator2>
std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1 && (*first1 == *first2)) {
    ++first1;
    ++first2;
  }
  return std::make_pair(first1, first2);
}

/**
 * version 2
 */
template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> mismatch(
    InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate _predicate) {
  while (first1 != last1 && _predicate(*first1, *first2)) {
    ++first1;
    ++first2;
  }
  return std::make_pair(first1, first2);
}
}  // namespace stdlib

bool predicate(int x, int y) {
  return (x == y);
}

int main() {
  std::vector<int> vt;
  vt.reserve(5);
  for (int i = 1; i < 6; ++i) {
    vt.push_back(i * 10);
  }

  int ints[] = {10, 20, 80, 320, 1024};

  std::pair<std::vector<int>::const_iterator, int *> pair;

  // using default comparison:
  pair = stdlib::mismatch(vt.cbegin(), vt.cend(), ints);

  std::cout << "First mismatching elements: " << *pair.first;
  std::cout << " and " << *pair.second << '\n';

  ++pair.first;
  ++pair.second;

  // using predicate comparison:
  pair = std::mismatch(pair.first, vt.cend(), pair.second, &predicate);
  std::cout << "Second mismatching elements: " << *pair.first;
  std::cout << " and " << *pair.second << '\n';

  return 0;
}