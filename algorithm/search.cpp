
/**
 * 在 ForwardIterator1[first1, last1) 中查找子串 ForwardIterator2[first2, last2).
 * 如果存在, 返回子串在 ForwardIterator1 中的第一个位置, 否则返回 last1
 */

namespace stdlib {
template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2) {
  if (first2 == last2) {
    return first1;
  }
  while (first1 != last1) {
    ForwardIterator1 it1 = first1;
    ForwardIterator2 it2 = first2;
    while (*it1 == *it2) {
      ++it1;
      ++it2;
      if (it2 == last2) { // 子串 ForwardIterator2 已到尾部
        return first1;
      }
      if (it1 == last1) { // 迭代器 ForwardIterator1 已到尾部, 说明子串后续节点不在 ForwardIterator1 中
        return last1;
      }
    }
    ++first1;
  }
  return last1;
}

template<typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
  ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate _predicate) {
  if (first2 == last2) {
    return first1;
  }
  while (first1 != last1) {
    ForwardIterator1 it1 = first1;
    ForwardIterator2 it2 = first2;
    while (_predicate(*it1, *it2)) {
      ++it1;
      ++it2;
      if (it2 == last2) { // 子串 ForwardIterator2 已到尾部
        return first1;
      }
      if (it1 == last1) { // 迭代器 ForwardIterator1 已到尾部, 说明子串后续节点不在 ForwardIterator1 中
        return last1;
      }
    }
    ++first1;
  }
  return last1;
}
}

#include <iostream>
#include <vector>

bool int_compare(int i, int j) {
  return (i == j);
}

int main() {
  std::vector<int> haystack;

  // set some values:        haystack: 10 20 30 40 50 60 70 80 90
  for (int i = 1; i < 10; i++) {
    haystack.push_back(i * 10);
  }

  // using default comparison:
  int needle1[] = {40, 50, 60, 70};
  std::vector<int>::iterator it;
  it = stdlib::search(haystack.begin(), haystack.end(), needle1, needle1 + 4);

  if (it != haystack.end()) {
    std::cout << "needle1 found at position " << (it - haystack.begin()) << '\n';
  } else {
    std::cout << "needle1 not found\n";
  }

  // using predicate comparison:
  int needle2[] = {20, 30, 50};
  it = stdlib::search(haystack.begin(), haystack.end(), needle2, needle2 + 3, int_compare);

  if (it != haystack.end()) {
    std::cout << "needle2 found at position " << (it - haystack.begin()) << '\n';
  } else {
    std::cout << "needle2 not found\n";
  }
  return 0;
}