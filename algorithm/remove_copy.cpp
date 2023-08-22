

/**
 * 将 [first, last) 中不等于 val 的元素拷贝到 OutputIterator
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename T>
OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T &val) {
  while (first != last) {
    if (*first != val) {
      *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}
}

#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int ints[] = {10, 20, 30, 30, 20, 10, 10, 20};

  std::vector<int> vt(std::distance(ints, std::end(ints)));

  stdlib::remove_copy(ints, std::end(ints), vt.begin(), 10);

  std::cout << "vt contains:" << '\n';
  for (const auto &item : vt) {
    std::cout << item << ' ';
  }

  return 0;
}