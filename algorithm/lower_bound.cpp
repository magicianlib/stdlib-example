#include <iterator>
#include <vector>
#include <iostream>

/**
 * lower_bound 本质就是二分查找, 在指定(有序)区域内查找不小于目标值的第一个元素
 */

namespace stdlib {
template<typename ForwardIterator, typename T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T val) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type DifferenceType;

  ForwardIterator it;
  DifferenceType count;
  DifferenceType step;

  count = std::distance(first, last);

  while (count > 0) {
    it = first;
    std::cout << "count = " << count << ", *it = " << *it;
    step = count / 2;
    std::advance(it, step);

    std::cout << ", step = " << step << ", *it = " << *it << '\n';

    if (*it < val) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

template<typename ForwardIterator, typename T, typename Compare>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T val, Compare _compare) {
  typedef typename std::iterator_traits<ForwardIterator>::difference_type DifferenceType;

  ForwardIterator it;
  DifferenceType count;
  DifferenceType step;

  count = std::distance(first, last);

  while (count > 0) {
    it = first;
    std::cout << "count = " << count << ", *it = " << *it;
    step = count / 2;
    std::advance(it, step);

    std::cout << ", step = " << step << ", *it = " << *it << '\n';

    if (_compare(*it, val)) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}
}

int main() {
  int ints[] = {1, 2, 3, 6, 7};
  std::vector<int> v(std::begin(ints), std::end(ints));

  std::vector<int>::iterator it;
  it = stdlib::lower_bound(v.begin(), v.end(), 10);

  std::cout << "lower_bound at position " << (it - v.begin()) << '\n';
  std::cout << "lower_bound at value " << (*it) << '\n';
}