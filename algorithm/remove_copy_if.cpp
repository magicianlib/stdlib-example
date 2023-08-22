
/**
 * 将范围 [first,last) 中的 _predicate == false 的元素复制到 result 中
 */

namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator remove_copy_if(InputIterator first,
  InputIterator last, OutputIterator result, UnaryPredicate _predicate) {
  while (first != last) {
    if (!_predicate(*first)) {
      *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}
}

#include <iostream>     // std::cout
#include <algorithm>    // std::remove_copy_if
#include <vector>       // std::vector

bool is_odd(int i) { return (i % 2); }

int main() {
  int ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vt(9);

  std::remove_copy_if(ints, ints + 9, vt.begin(), &is_odd);

  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}