#include <iostream>
#include <iterator>
#include <vector>

/**
 * copy 将 [first,last) 范围元素拷贝到 result.
 * <br>
 * OutputIterator 不会触发扩容, 应该提前准备足够容量.
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result) {
  while (first != last) {
    *result = *first;
    ++result;
    ++first;
  }
  return result; // 返回 OutputIterator 最后一个迭代器, 可用于后续操作
}
}

int main() {
  int ints[] = {10, 20, 30, 40, 50, 60, 70};

  std::vector<int> vt(10); // 分配 10 个单位空间.

  std::vector<int>::iterator end = stdlib::copy(std::begin(ints), std::end(ints), vt.begin());

  vt.resize(end - vt.begin()); // 删除冗余空间

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}