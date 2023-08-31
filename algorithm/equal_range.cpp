#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

/**
 * ForwardIterator 必须是有序迭代器
 */
namespace stdlib {
template<class ForwardIterator, class T>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T &val) {
  // 利用 lower_bound 查找第一个不小于(大于或等于) val 元素的位置
  ForwardIterator it = std::lower_bound(first, last, val);
  // 继续在 [it, last) 范围内查找第一个大于 val 元素的位置.
  return std::make_pair(it, std::upper_bound(it, last, val));
}

/*template<class ForwardIterator, class T, typename Compare>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T &val, Compare _compare) {
  ForwardIterator it = std::lower_bound(first, last, val);
  return std::make_pair(it, std::upper_bound(it, last, val));
}*/
}

bool greater(int i, int j) { return (i > j); }

int main() {

  int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};

  std::vector<int> v(myints, myints + 8);                         // 10 20 30 30 20 10 10 20

  std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;

  // using default comparison:
  std::sort(v.begin(), v.end());                                   // 10 10 10 20 20 20 30 30
  bounds = stdlib::equal_range(v.begin(), v.end(), 20);       //          ^        ^

  std::cout << *bounds.first << ' ' << *bounds.second << '\n';

  // using "greater" as comp:
  std::sort(v.begin(), v.end(), greater);                            // 30 30 20 20 20 10 10 10
  bounds = std::equal_range(v.begin(), v.end(), 20, greater); //       ^        ^

  std::cout << "bounds at positions " << (bounds.first - v.begin());
  std::cout << " and " << (bounds.second - v.begin()) << '\n';

  return 0;
}