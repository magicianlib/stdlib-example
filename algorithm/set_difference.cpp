#include <algorithm>

/**
 * 从 InputIterator1 中查找不在 InputIterator2 中的元素
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2, OutputIterator result) {
  while (first1 != last2 && first2 != last2) {
    if (*first1 < *first2) {
      *result = *first1;
      ++result;
      ++first1;
    } else if (*first2 < *first1) {
      ++first2;
    } else {
      ++first1;
      ++first2;
    }
  }
  // 如果 InputIterator2 元素个数少于 InputIterator1, 则将 InputIterator1 后续的元素全部拷贝到 result 中
  return std::copy(first1, last1, result);
}

template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2, OutputIterator result, Compare _compare) {
  while (first1 != last2 && first2 != last2) {
    if (_compare(*first1, *first2)) {
      *result = *first1;
      ++result;
      ++first1;
    } else if (_compare(*first2, *first1)) {
      ++first2;
    } else {
      ++first1;
      ++first2;
    }
  }
  // 如果 InputIterator2 元素个数少于 InputIterator1, 则将 InputIterator1 后续的元素全部拷贝到 result 中
  return std::copy(first1, last1, result);
}
}

#include <iostream>
#include <vector>
#include <iterator>

int main() {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};

  std::vector<int> vt(10);
  std::vector<int>::iterator it;

  std::sort(first, std::end(first));
  std::sort(second, std::end(second));

  it = stdlib::set_difference(first, std::end(first), second, std::end(second), vt.begin());

  vt.resize(std::distance(vt.begin(), it));

  std::cout << "The difference has " << (vt.size()) << " elements:\n";
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}