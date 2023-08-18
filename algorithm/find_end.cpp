#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

/**
 * 在指定范围内 [first1,last1) 查找由 [first2,last2) 子串最后一次出现的位置.
 * 并返回第一个元素的迭代器(first1); 如果没有找到, 则返回last1.
 */

namespace stdlib {
template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_end(
  ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2) {

  if (first2 == last2) {
    return last1;
  }

  ForwardIterator1 ret = last1;
  while (first1 != last1) {
    ForwardIterator1 f1 = first1;
    ForwardIterator2 f2 = first2;
    while (*f1 == *f2) {
      ++f1;
      ++f2;
      if (f2 == last2) { // f2 is over.
        ret = first1;
        break;
      }
      if (f1 == last1) { // f1 is over.
        return ret;
      }
    }
    ++first1;
  }
  return ret;
}

template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 find_end(
  ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate _predicate) {

  if (first2 == last2) {
    return last1;
  }

  ForwardIterator1 ret = last1;
  while (first1 != last1) {
    ForwardIterator1 f1 = first1;
    ForwardIterator2 f2 = first2;
    while (_predicate(*f1, *f2)) {
      ++f1;
      ++f2;
      if (f2 == last2) { // f2 is over.
        ret = first1;
        break;
      }
      if (f1 == last1) { // f1 is over.
        return ret;
      }
    }
    ++first1;
  }
  return ret;
}
}

bool equal_predicate(int v1, int v2) {
  return v1 == v2;
}

int main() {

  std::vector<int> vt(10);
  std::iota(vt.begin(), vt.end(), 1);

  int needle1[] = {1, 2, 3};

  // using default comparison:
  std::vector<int>::const_iterator it;
  it = stdlib::find_end(vt.cbegin(), vt.cend(), needle1, std::end(needle1));

  if (it != vt.cend()) {
    std::cout << "needle1 last found at position " << (it - vt.cbegin()) << '\n';
  }

  // resize
  vt.push_back(4);
  vt.push_back(5);
  vt.push_back(1);

  int needle2[] = {4, 5, 1};

  // using predicate comparison:
  it = stdlib::find_end(vt.cbegin(), vt.cend(), needle2, std::end(needle2), &equal_predicate);

  if (it != vt.cend()) {
    std::cout << "needle2 last found at position " << (it - vt.cbegin()) << '\n';
  }

  return 0;
}