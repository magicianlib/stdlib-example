#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>

/**
 * 用于在给定范围内删除满足特定条件的元素, 并将不满足条件的元素移动到范围的末尾. 它并不会
 * 真正从容器中删除元素, 而是将不满足条件的元素移动到末尾, 并返回新的逻辑结束位置的迭代器.
 * <br>
 * 注意, remove 并不会改变迭代器大小. 内部的处理流程是将不等于 val 的元素向前移动, 并
 * 返回一个新的尾指针 pend. 即将原迭代器分为: [first, pend), [pend, last).
 * 如果 pend == last 说明没有等于 val 的元素.
 */

namespace stdlib {
template<typename ForwardIterator, typename T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T &val) {
  ForwardIterator result = first;
  while (first != last) {
    if (!(*first == val)) {
      if (result != first) {
        *result = std::move(*first);
      }
      ++result;
    }
    ++first;
  }
  return result;
}
}  // namespace stdlib

int main() {
  int ints[] = {10, 20, 30, 30, 20, 10, 10, 20};

  int *begin = ints;
  int *end = std::end(ints);

  int *bound = stdlib::remove(begin, end, 20);

  for (int *p = begin; p != bound; ++p) {
    std::cout << *p << ' ';
  }
  std::cout << '\n';

  for (int *p = bound; p != end; ++p) {
    std::cout << *p << ' ';
  }
  std::cout << '\n';

  return 0;
}