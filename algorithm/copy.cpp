#include <iostream>
#include <iterator>
#include <vector>

/**
 * copy 将 [first,last) 范围元素拷贝到 out 头部(等同 std::front_inserter).
 *
 * OutputIterator 不会触发扩容, 应该提前准备足够容量.
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator out) {
  while (first != last) {
    *out = *first;
    ++out;
    ++first;
  }
  return out;
}
}

int main() {
  int ints[] = {10, 20, 30, 40, 50, 60, 70};

  std::vector<int> vt(6);
  vt.push_back(100); // 100 将不会被覆盖

  stdlib::copy(std::begin(ints), std::end(ints), vt.begin());

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}