
/**
 * 移除连续范围内相同元素(保留第一个)
 */

namespace stdlib {
template<typename ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last) {
  ForwardIterator result = first;
  while (++first != last) {
    if (!(*result == *first)) {
      *(++result) = *first;
    }
  }
  return result;
}

template<typename ForwardIterator, typename BinaryPredicate>
ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate _predicate) {
  ForwardIterator result = first;
  while (++first != last) {
    if (!_predicate(*result, *first)) {
      *(++result) = *first;
    }
  }
  return result;
}
}

#include <iostream>
#include <vector>

bool myfunction(int i, int j) {
  return (i == j);
}

int main() {
  int ints[] = {10, 20, 20, 20, 30, 30, 20, 20, 10};           // 10 20 20 20 30 30 20 20 10
  std::vector<int> vt(ints, ints + 9);

  // using default comparison:
  std::vector<int>::iterator it;
  it = stdlib::unique(vt.begin(), vt.end());   // 10 20 30 20 10 ?  ?  ?  ?
  //                ^

  vt.resize(std::distance(vt.begin(), it)); // 10 20 30 20 10

  // using predicate comparison:
  stdlib::unique(vt.begin(), vt.end(), myfunction);   // (no changes)

  // print out content:
  std::cout << "vt contains:";
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}