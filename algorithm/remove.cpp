#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>

/**
 * *删除* [first,last) 中等于val的所有元素, 并返回一个指向该范围新末尾的迭代器.
 *
 * 注意, remove 并不会改变迭代器大小. 内部的处理流程是将不等于 val 的元素向前移动,
 * 并返回一个新的尾指针 pend. 即将原迭代器分为: [first, pend), [pend, last).
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
}

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