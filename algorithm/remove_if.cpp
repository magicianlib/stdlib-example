
/**
 * @see std::remove
 */

namespace stdlib {
template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate _predicate) {
  ForwardIterator result = first;
  while (first != last) {
    if (!_predicate(*first)) {
      if (result != first) {
        *result = *first;
      }
      ++result;
    }
    ++first;
  }
  return result;
}
}

// remove_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::remove_if

bool is_odd(int i) { return ((i % 2) == 1); }

int main() {
  int ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};            // 1 2 3 4 5 6 7 8 9

  // bounds of range:
  int *begin = ints;
  int *pend = ints + sizeof(ints) / sizeof(int);

  pend = std::remove_if(begin, pend, is_odd);   // 2 4 6 8 ? ? ? ? ?

  std::cout << "the range contains:";
  for (int *p = begin; p != pend; ++p) {
    std::cout << ' ' << *p;
  }
  std::cout << '\n';

  return 0;
}