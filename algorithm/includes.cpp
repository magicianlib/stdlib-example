#include <iterator>
#include <iostream>
#include <algorithm>

/**
 * includes 判断 InputIterator1 是否包含 InputIterator2 全部元素.
 * 需要保证 InputIterator1 和 InputIterator1 都是有序迭代器(std::sort);
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2>
bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
  while (first2 != last2) {

    // 边界处理

    // 因为 InputIterator1 和 InputIterator2 都是有序迭代器, 因此 *first2 必须大于或等于 *first1.
    // 反过来就是如果 (*first2 < *first1) 说明 *first2 不在 InputIterator1 中.

    // 另外, 如果 (first1 == last1), 表示 InputIterator1 已经没有后续元素了, 说明后续的 *first2 不在
    // InputIterator1 中.

    if (first1 == last1 || *first2 < *first1) {
      return false;
    }

    std::cout << "*first1 = " << *first1 << " "
              << "*first2 = " << *first2 << " "
              << "!(*first1 < first2) = " << !(*first1 < *first2)
              << '\n';

    // 边界处理完成后, 只需要保证 *first1 大于或等于 *first2 即可(!(*first1 < *first2)).
    // 如果 !(*first1 < *first2) 继续判断 InputIterator2 的后续元素.

    if (!(*first1 < *first2)) {
      ++first2;
    }
    ++first1;
  }
  return true;
}

template<typename InputIterator1, typename InputIterator2, typename Compare>
bool includes(InputIterator1 first1,
  InputIterator1 last1,
  InputIterator2 first2,
  InputIterator2 last2,
  Compare _compare) {
  while (first2 != last2) {
    if (first1 == last1 || _compare(*first2, *first1)) {
      return false;
    }
    std::cout << "*f"
                 "irst1 = " << *first1 << " "
              << "*first2 = " << *first2 << " "
              << "!(*first1 < first2) = " << !(*first1 < *first2)
              << '\n';
    if (!_compare(*first1, *first2)) {
      ++first2;
    }
    ++first1;
  }
  return true;
}
}

bool compare_fn(int i, int j) { return i < j; }

int main() {
  int container[] = {5, 10, 20, 30};
  int continent1[] = {10, 20, 30};

  std::sort(container, std::end(container));
  std::sort(continent1, std::end(continent1));

  std::cout << "using default comparison:" << '\n';
  std::cout << '\n';

  if (stdlib::includes(container, std::end(container), continent1, std::end(continent1))) {
    std::cout << "container includes continent1!" << '\n';
  } else {
    std::cout << "container not includes continent1!" << '\n';
  }

  std::cout << '\n';

  int continent2[] = {10, 10, 20, 30}; // 多了一个重复元素 10
  if (stdlib::includes(container, std::end(container), continent2, std::end(continent2))) {
    std::cout << "container includes continent2!" << '\n';
  } else {
    std::cout << "container not includes continent2!" << '\n';
  }
  std::cout << '\n';

  int container1[] = {5, 10, 10, 20, 30}; // 与 continent2 一致
  if (stdlib::includes(container1, std::end(container1), continent2, std::end(continent2))) {
    std::cout << "container1 includes continent2!" << '\n';
  } else {
    std::cout << "container1 not includes continent2!" << '\n';
  }

  std::cout << '\n';

  std::cout << "using compare_fn as comp:" << '\n';
  std::cout << '\n';

  if (stdlib::includes(container, std::end(container), continent1, std::end(continent1), &compare_fn)) {
    std::cout << "container includes continent1!" << '\n';
  } else {
    std::cout << "container not includes continent1!" << '\n';
  }

  return 0;
}