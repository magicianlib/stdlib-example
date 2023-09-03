#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

/**
 * std::partition_point 是 C++ 标准库中的一个算法, 用于在给定范围内找到一个分区点(使得满足 p 的元素位于该点的
 * 前面, 而不满足 p 的元素则位于该点的后面. 函数返回一个迭代器，指向该分区点).
 * <br>
 * 与 std::partition 不同的是, std::partition_point 仅返回一个分区点，而不是对
 * 整个范围进行分区.
 */

namespace stdlib {
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator partition_point(ForwardIterator first, ForwardIterator last, UnaryPredicate _predicate) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type DifferenceType;

  DifferenceType n = std::distance(first, last);
  while (n > 0) {
    ForwardIterator it = first;
    DifferenceType step = n / 2;
    std::advance(it, step);
    if (_predicate(*it)) {
      first = ++it;
      n -= step + 1;
    } else {
      n = step;
    }
  }
  return first;
}
}

bool is_odd(int v) {
  return (v % 2);
}

int main() {
  std::vector<int> foo{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> odd;

  std::partition(foo.begin(), foo.end(), &is_odd);

  auto it = stdlib::partition_point(foo.begin(), foo.end(), &is_odd);
  odd.assign(foo.begin(), it);

  // print contents of odd:
  std::cout << "odd:";
  for (int &x : odd) {
    std::cout << ' ' << x;
  }
  std::cout << '\n';

}