#include <string>
#include <utility>
#include <iostream>

/**
 *
 */

namespace stdlib {
template<typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 move_backward(BidirectionalIterator1 first,
  BidirectionalIterator1 last, BidirectionalIterator2 result) {
  while (last != first) {
    *(--result) = std::move(*(--last));
  }
  return result;
}
}

int main() {
  std::string elems[10] = {"air", "water", "fire", "earth"};

  // insert new element at the beginning:
  std::move_backward(elems, elems + 4, elems + 10);
  elems[0] = "ether";

  std::cout << "elems contains:";
  for (const auto & elem : elems) {
    std::cout << " [" << elem << "]";
  }
  std::cout << '\n';
  return 0;
}