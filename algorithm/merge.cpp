#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>

/**
 * 将两个有序迭代器(InputIterator1, InputIterator1)合并输出到 OutputIterator.
 * InputIterator1 和 InputIterator1 必须具有相同的排序规则, 如全升序或全降序.
 *
 * @see inplace_merge
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2, OutputIterator out) {

  while (true) {
    if (first1 == last1) { // 处理边界(InputIterator1没有后续元素)
      return std::copy(first2, last2, out);
    }
    if (first2 == last2) { // 处理边界(InputIterator2没有后续元素)
      return std::copy(first1, last1, out);
    }
    *out++ = (*first1 < *first2) ? *first1++ : *first2++;
  }
}

template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2, OutputIterator out, Compare _compare) {
  while (true) {
    if (first1 == last1) { // 处理边界(InputIterator1没有后续元素)
      return std::copy(first2, last2, out);
    }
    if (first2 == last2) { // 处理边界(InputIterator2没有后续元素)
      return std::copy(first1, last1, out);
    }
    *out++ = _compare(*first1, *first2) ? *first1++ : *first2++;
  }
}
}

int main() {

  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};

  std::sort(first, std::end(first));
  std::sort(second, std::end(second));

  long cap = std::distance(first, std::end(first)) + std::distance(second, std::end(second));

  std::vector<int> vt(cap);

  stdlib::merge(first, std::end(first), second, std::end(second), vt.begin());

  std::cout << "The resulting vector contains:";

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}