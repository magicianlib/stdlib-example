#include <iterator>

/**
 * 移除连续范围内相同元素(保留第一个)
 */

namespace stdlib {
template<typename ForwardIterator, typename OutputIterator>
OutputIterator unique_copy(ForwardIterator first, ForwardIterator last, OutputIterator result) {
  if (first == last) {
    return result;
  }

  *result = *first;
  while (++first != last) {
    typename std::iterator_traits<ForwardIterator>::value_type val = *first;
    if (!(*result == val)) {
      *(++result) = val;
    }
  }
  return result;
}

template<typename ForwardIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator unique_copy(
    ForwardIterator first, ForwardIterator last, OutputIterator result, BinaryPredicate _predicate) {
  if (first == last) {
    return result;
  }

  *result = *first;
  while (++first != last) {
    typename std::iterator_traits<ForwardIterator>::value_type val = *first;
    if (!_predicate(*result, val)) {
      *(++result) = val;
    }
  }
  return ++result;
}
}  // namespace stdlib

#include <algorithm>
#include <iostream>
#include <vector>

bool myfunction(int i, int j) {
  return (i == j);
}

int main() {
  int myints[] = {10, 20, 20, 20, 30, 30, 20, 20, 10};
  std::vector<int> myvector(9);  // 0  0  0  0  0  0  0  0  0

  // using default comparison:
  std::vector<int>::iterator it;
  it = stdlib::unique_copy(myints, myints + 9, myvector.begin());  // 10 20 30 20 10 0  0  0  0
  //                ^

  std::sort(myvector.begin(), it);  // 10 10 20 20 30 0  0  0  0
  //                ^

  // using predicate comparison:
  it = stdlib::unique_copy(myvector.begin(), it, myvector.begin(), myfunction);
  // 10 20 30 20 30 0  0  0  0
  //          ^

  myvector.resize(std::distance(myvector.begin(), it));  // 10 20 30

  // print out content:
  std::cout << "myvector contains:";
  for (it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}