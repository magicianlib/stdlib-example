#include <iomanip>
#include <cctype>
#include <iterator>
#include <algorithm>
#include <iostream>

/**
 * 按照字典顺序比较两个序列. 如果第一个序列小于第二个序列, 则返回true, 否则返回false.
 * <br>
 * 如果每个位置的元素都相同, 元素个数少的一方更小.
 */

namespace stdlib {

/**
 *  按照词典法 InputIterator1 是否小于 InputIterator2
 */
template<typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
  while (first1 != last1) {
    if (first2 == last2 || (*first2 < *first1)) { // InputIterator2 元素数量更少或 *first2 小于 *first1
      return false;
    } else if (*first1 < *first2) { // *first1 小于 *first2
      return true;
    }
    ++first1;
    ++first2;
  }

  // 如果 InputIterator1 已经没有后续元素, 继续判断下 InputIterator2 是否还有后续元素
  return (first2 != last2);
}

/**
 *  按照词典法 InputIterator1 是否小于 InputIterator2
 */
template<typename InputIterator1, typename InputIterator2, typename Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2, Compare _compare) {
  while (first1 != last1) {
    if (first2 == last2 || _compare(*first2, *first1)) { // InputIterator2 元素数量更少或 *first2 小于 *first1
      return false;
    } else if (_compare(*first1, *first2)) { // *first1 小于 *first2
      return true;
    }
    ++first1;
    ++first2;
  }

  // 如果 InputIterator1 已经没有后续元素, 继续判断下 InputIterator2 是否还有后续元素
  return (first2 != last2);
}
}

bool char_cmp(char c1, char c2) {
  return std::tolower(c1) < std::tolower(c2);
}

int main() {
  char foo[] = "apple";
  char bar[] = "apartment";

  std::cout << std::boolalpha;
  std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
  std::cout << stdlib::lexicographical_compare(foo, std::end(foo), bar, std::end(bar)) << '\n';
  std::cout << '\n';

  std::cout << "Using char_cmp as comparison object: \n";
  std::cout << std::lexicographical_compare(foo, std::end(foo), bar, std::end(bar), &char_cmp);
  std::cout << '\n';

  return 0;
}