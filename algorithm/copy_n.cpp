#include <iostream>
#include <iterator>
#include <vector>

/**
 * 将 InputIterator 前 Size 个元素拷贝到 OutputIterator.
 * InputIterator 和 OutputIterator 不保证边界问题.
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename Size>
OutputIterator copy_n(InputIterator first, OutputIterator out, Size _size) {
  while (_size-- > 0) {
    *out++ = *first++;
  }
  return out;
}
}

int main() {
  int ints[] = {1, 2, 3, 4, 5, 6, 7};

  std::vector<int> vt(std::distance(std::begin(ints), std::end(ints)));

  stdlib::copy_n(std::begin(ints), vt.begin(), vt.size() / 2 + 1);

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}