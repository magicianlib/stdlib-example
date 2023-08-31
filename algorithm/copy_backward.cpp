#include <iostream>
#include <iterator>
#include <vector>
#include <iomanip>

/**
 * 从尾部开始拷贝元素
 * <br>
 * BidirectionalIterator2 不会触发扩容, 应该提前准备足够容量.
 */
namespace stdlib {
template<typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 copy_backward(BidirectionalIterator1 first1,
  BidirectionalIterator1 last1, BidirectionalIterator2 last2) {
  while (first1 != last1) {
    *(--last2) = *(--last1);
  }
  return last2;
}
}

int main() {
  int ints[] = {10, 20, 30, 40, 50, 60, 70};

  std::vector<int> vt(std::begin(ints), std::end(ints));
  vt.resize(vt.size() + 3); // 10 20 30 40 50 60 70 0 0 0

  std::vector<int>::iterator it;

  std::cout << "before: ";
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << std::setw(2) << *it;
  }
  std::cout << '\n';

  // before: 10 20 30 40 50 60 70 0 0 0

  stdlib::copy_backward(vt.begin(), (vt.begin() + 7), vt.end());

  std::cout << " after: ";
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << std::setw(2) << *it;
  }
  std::cout << '\n';

  // after: 10 20 30 10 20 30 40 50 60 70
}