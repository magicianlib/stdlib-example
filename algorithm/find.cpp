#include <iostream>
#include <iterator>
#include <vector>

/**
 * 在指定范围内 [first, last) 查找第一个与val相等的元素的迭代器, 如果找不到就返回 last.
 */

namespace stdlib {
template<typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T &val) {
  while (first != last) {
    if (*first == val) {
      return first;
    }
    ++first;
  }
  return last;
}
}

int main() {
  int ints[] = {10, 20, 30, 40};

  int *find = stdlib::find(std::begin(ints), std::end(ints), 30);
  if (find != std::end(ints)) {
    std::cout << "Element found in ints: " << *find << '\n';
  } else {
    std::cout << "Element not found in ints\n";
  }

  std::vector<int> vt(std::begin(ints), std::end(ints));
  std::vector<int>::const_iterator it;

  it = stdlib::find(vt.cbegin(), vt.cend(), 30);
  if (it != vt.cend()) {
    std::cout << "Element found in vt: " << *it << '\n';
  } else {
    std::cout << "Element not found in vt\n";
  }

  return 0;
}