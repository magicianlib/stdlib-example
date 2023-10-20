#include <algorithm>
#include <iostream>
#include <vector>

namespace stdlib {

/**
 * adjacent_find 返回发现的第一个相邻元素相同的 Iterator, 并不代表 <code>++Iterator</code> 是下一个相邻相同的元素.
 * <br>
 * ForwardIterator [begin end], Iterator 值为 [begin end] 中的任意一个指针.
 * <br>
 * 因此 Iterator 本意是 ForwardIterator + (end - begin).
 */

template<typename ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last) {
  if (first != last) {
    ForwardIterator next = first;
    ++next;
    while (next != last) {
      if (*first == *next) {
        return first;
      }
      ++first;
      ++next;
    }
  }
  return last;
}

template<typename ForwardIterator, typename BinaryPredicate>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate _predicate) {
  if (first != last) {
    ForwardIterator next = first;
    ++next;
    while (next != last) {
      if (_predicate(*first, *next)) {
        return first;
      }
      ++first;
      ++next;
    }
  }
  return last;
}

}  // namespace stdlib

/**
 * 自定义二元谓词
 */
bool binary_pred(const int x, const int y) {
  return x == y;
}

int main() {
  int nums[] = {5, 20, 5, 30, 30, 20, 10, 10, 20};

  std::vector<int> vt(nums, nums + 8);
  std::vector<int>::iterator it;

  it = stdlib::adjacent_find(vt.begin(), vt.end());
  if (it != vt.end()) {
    std::cout << "the first pair of repeated elements are: " << *it << '\n';
  }

  it = stdlib::adjacent_find(++it, vt.end(), &binary_pred);
  if (it != vt.end()) {
    std::cout << "the second pair of repeated elements are: " << *it << '\n';
  }

  return 0;
}