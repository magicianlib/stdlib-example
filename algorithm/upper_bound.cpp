#include <iterator>
#include <vector>
#include <iostream>

/**
 * upper_bound 本质就是二分查找
 * <br>
 * 在<em>有序</em>序列中查找第一个<em>大于</em>目标值元素的位置
 */

namespace stdlib {
template<typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T val) {
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

    if (!(val < *it)) {
      first = ++it;
      count -= step + 1;
    } else {
      count = step;
    }
  }
  return first;
}

template<typename ForwardIterator, typename T, typename Compare>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T val, Compare _compare) {
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

    if (!_compare(*it, val)) {
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
  it = stdlib::upper_bound(v.begin(), v.end(), 10);

  std::cout << "lower_bound at position " << (it - v.begin()) << '\n';
  std::cout << "lower_bound at value " << (*it) << '\n';
}