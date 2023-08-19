#include <iostream>     // std::cout
#include <algorithm>    // std::inplace_merge, std::sort, std::copy
#include <vector>       // std::vector

/**
 * 将一个有序迭代器(InputIterator) 两个区间段 [first, middle) [middle, last) 合并到输出到 OutputIterator.
 *
 * 两个区间段必须有相同的排序规则, 如全升序或全降序.
 *
 * 示例: [2, 3, 4, 5, 1, 3, 5]
 *
 * 有序区间1: [2, 3, 4, 5],
 * 有序区间2: [1, 3, 5]
 *
 * 合并输出后: [1, 2, 3, 3, 4, 5, 5]
 *
 * @see merge
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator>
OutputIterator inplace_merge(InputIterator first, InputIterator middle, InputIterator last, OutputIterator out);

template<typename InputIterator, typename OutputIterator, typename Compare>
OutputIterator inplace_merge(InputIterator first, InputIterator middle, InputIterator last,
  OutputIterator out, Compare _compare);
}

int main() {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};

  std::vector<int> v(10);
  std::vector<int>::iterator it;

  std::sort(first, first + 5);
  std::sort(second, second + 5);

  it = std::copy(first, first + 5, v.begin());
  std::copy(second, second + 5, it);

  std::inplace_merge(v.begin(), v.begin() + 5, v.end());

  std::cout << "The resulting vector contains:";
  for (it = v.begin(); it != v.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}