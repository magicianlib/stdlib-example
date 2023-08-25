#include <algorithm>

namespace stdlib {
template<typename BidirectionalIterator, typename OutputIterator>
void reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result) {
  while (first != last) {
    --last;
    *result = *last;
    ++result;
  }
}
}

#include <iostream>
#include <vector>

int main() {
  int ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vt;

  vt.resize(9);    // allocate space

  std::reverse_copy(ints, ints + 9, vt.begin());

  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }

  std::cout << '\n';

  return 0;
}