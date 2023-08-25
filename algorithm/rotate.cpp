#include <algorithm>

/**
 * 将 [first, middle) 和 [middle, last) 位置互换, 即得到 [middle, last-1, first)
 */
namespace stdlib {
template<typename ForwardIterator>
void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last) {
  ForwardIterator next = middle;
  while (first != next) {
    std::swap(*first++, *next++);
    if (next == last) {
      next = middle;
    } else if (first == middle) {
      middle = next;
    }
  }
}
}

#include <vector>
#include <iostream>

int main() {
  std::vector<int> vt;

  // set some values:
  for (int i = 1; i < 10; ++i) {
    vt.push_back(i);
  } // 1 2 3 4 5 6 7 8 9

  stdlib::rotate(vt.begin(), vt.begin() + 3, vt.end());
  // 4 5 6 7 8 9 1 2 3
  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}