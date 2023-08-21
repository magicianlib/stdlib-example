#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

/**
 * 复制 [first,last) 到 [result_first, result_last) 范围内的最小元素，并对
 * 复制的元素进行排序. 复制的元素数量与 result_first 和 result_last 之间的距
 * 离相同.
 *
 * 如果 result_first 和 result_last 之间的距离 大于 first 和 last 之间的距离,
 * 那么最大拷贝 (last - first) 个数量元素
 */

namespace stdlib {
template<typename InputIterator, typename RandomAccessIterator>
void partial_sort_copy(InputIterator first, InputIterator last,
  RandomAccessIterator result_first, RandomAccessIterator result_last);

template<typename InputIterator, typename RandomAccessIterator, typename Compare>
void partial_sort_copy(InputIterator first, InputIterator last,
  RandomAccessIterator result_first, RandomAccessIterator result_last, Compare _compare);
}

bool int_compare(int x, int y) {
  return (x < y);
}

int main() {
  int ints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> vt(5);

  // using default comparison (operator <):
  std::partial_sort_copy(ints, ints + 9, vt.begin(), vt.end());

  // using function as comp
  std::partial_sort_copy(ints, ints + 9, vt.begin(), vt.end(), &int_compare);

  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
  return 0;
}