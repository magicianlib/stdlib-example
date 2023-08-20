#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

/**
 * 返回第一个 _predicate(*ForwardIterator) 为 false 的迭代器, 使用前提是已经执行过 partition(first, last)
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