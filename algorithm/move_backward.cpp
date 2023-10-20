#include <iostream>
#include <string>
#include <utility>

/**
 * 用于将元素从给定范围的起始位置移动到结束位置, 同时保留元素的原有顺序.
 * <br>
 * 函数会将从 first 到 last 的元素逆序移动到从 result-1 到 first+last-1 的位置上, 并返回目标范围的结束位置.
 */

namespace stdlib {
template<typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 move_backward(
    BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result) {
  while (last != first) {
    *--result = std::move(*--last);
  }
  return result;
}
}  // namespace stdlib

int main() {
  std::string elems[10] = {"air", "water", "fire", "earth"};

  // insert new element at the beginning:
  std::move_backward(elems, elems + 4, elems + 10);
  elems[0] = "ether";

  std::cout << "elems contains:";
  for (const auto& elem : elems) {
    std::cout << " [" << elem << "]";
  }
  std::cout << '\n';
  return 0;
}