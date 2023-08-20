#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

/**
 * 重新排列范围 [first,last) 中的元素, 使得 pred 返回 true 的所有元素先于返回 false 的所有元素.
 * 迭代器返回指向第二组的第一个元素的点。
 */

namespace stdlib {
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    while (_predicate(*first)) { // 结果为 true, 直到遇到 false
      ++first;
      if (first == last) {
        return first;
      }
    }
    do {
      --last; // 从尾部开始
      if (first == last) {
        return first;
      }
    } while (!_predicate(*last)); // 遇到的第一个 true
    std::swap(*first, *last); // 交换
    ++first; // 继续查找下一个
  }
  return first;
}
}

bool is_odd(int v) {
  return (v % 2);
}

int main() {
  std::vector<int> vt(10);
  std::iota(vt.begin(), vt.end(), 1);

  std::cout << "before partition:" << '\n';
  for (const auto &item : vt) {
    std::cout << item << ' ';
  }
  std::cout << '\n';

  std::vector<int>::iterator bound;

  std::cout << "after partition:" << '\n';
  bound = stdlib::partition(vt.begin(), vt.end(), &is_odd);
  for (const auto &item : vt) {
    std::cout << item << ' ';
  }
  std::cout << '\n';

  std::cout << "odd: ";
  for (auto it = vt.begin(); it != bound; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  std::cout << "even: ";
  for (; bound != vt.end(); ++bound) {
    std::cout << *bound << ' ';
  }
  std::cout << '\n';

}