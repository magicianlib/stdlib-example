#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cctype>    // std::tolower

/**
 * 在指定范围内 [first1,last1) 查找由 [first2,last2) 子串任意一个元素,
 * 并返回第一次出现的位置first1. 如果没有找到, 则返回last1.
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2>
InputIterator1 find_first_of(
  InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2) {

  if (first2 == last2) {
    return last1;
  }

  while (first1 != last1) {
    for (InputIterator2 it = first2; it != last2; ++it) {
      if (*it == *first1) {
        return first1;
      }
    }
  }
  return last1;
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
InputIterator1 find_first_of(
  InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2,
  BinaryPredicate _predicate) {

  if (first2 == last2) {
    return last1;
  }

  while (first1 != last1) {
    for (InputIterator2 it = first2; it != last2; ++it) {
      if (_predicate(*it, *first1)) {
        return first1;
      }
    }
  }
  return last1;
}
}

bool comp_case_insensitive(char c1, char c2) {
  return (std::tolower(c1) == std::tolower(c2));
}

int main() {
  int chars[] = {'a', 'b', 'c', 'A', 'B', 'C'};
  std::vector<char> haystack(chars, chars + 6);
  std::vector<char>::iterator it;

  int needle[] = {'A', 'B', 'C'};

  // using default comparison:
  it = find_first_of(haystack.begin(), haystack.end(), needle, std::end(needle));

  if (it != haystack.end()) {
    std::cout << "The first match is: " << *it << '\n';
  }

  // using predicate comparison:
  it = find_first_of(haystack.begin(), haystack.end(), needle, std::end(needle), &comp_case_insensitive);

  if (it != haystack.end()) {
    std::cout << "The first match is: " << *it << '\n';
  }

  return 0;
}