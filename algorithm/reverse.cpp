#include <algorithm>

namespace stdlib {
template<typename BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last) {
  while ((first != last) && (first != --last)) {
    std::iter_swap(first, last);
    ++first;
  }
}
}  // namespace stdlib

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vt;

  // set some values:
  for (int i = 1; i < 10; ++i) {
    vt.push_back(i);
  }  // 1 2 3 4 5 6 7 8 9

  std::reverse(vt.begin(), vt.end());  // 9 8 7 6 5 4 3 2 1

  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}