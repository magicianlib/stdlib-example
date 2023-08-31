#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <tuple>

/**
 * 该函数的作用是判断序列 [first1, last1) 是否和序列 [first2, first2+(std::distance(first1, last1)) 是排列.
 * 也就是说, 它判断两个序列是否包含相同的元素, 只是顺序不同.
 * <br>
 * 注意, 最多比较大小为 [first1, last1) [first2, first2+(std::distance(first1, last1)).
 * 如:
 *    foo = {1, 2, 3, 4, 5};
 *    bar = {3, 1, 4, 5, 2};
 *    - 那么 foo 和 bar 具有相同的元素
 *  如果:
 *    bar = {3, 1, 4, 5, 0, 2};
 *    - 则 foo 和 bar 具有不同的元素， 因为真正比较时 bar = {3, 1, 4, 5, 0}; 最后一个 2 会被忽略.
 */

namespace stdlib {
template<typename InputIterator1, typename InputIterator2>
bool is_permutation(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {

  // 得到返回两个序列中不匹配的第一个元素
  std::tie(first1, first2) = std::mismatch(first1, last1, first2);

  // 如果 first1 == last1 说明 InputIterator1 已经比较完(InputIterator2 比 InputIterator1 元素更多)
  if (first1 == last1) {
    return true;
  }

  // 虚拟 InputIterator2 的最后一个元素
  // 将 last2 前进 std::distance(first1, last2) 个位置, 就能得到与 InputIterator1 相同的元素数量
  // 也就是说 InputIterator2 元素数量必须不少于 InputIterator1
  InputIterator2 last2 = first2;
  std::advance(last2, std::distance(first1, last2));

  for (InputIterator1 it = first1; it != last1; ++it) {
    if (std::find(first1, it, *it) == it) {
      auto n = std::count(first2, last2, *it);
      if (n == 0 || std::count(it, last1, *it) != n) {
        return false;
      }
    }
  }
  return true;
}
}

int main() {

  std::array<int, 6> foo = {1, 1, 2, 3, 4, 5};
  std::array<int, 6> bar = {3, 1, 4, 5, 2, 1};

  if (stdlib::is_permutation(foo.begin(), foo.end(), bar.begin())) {
    std::cout << "foo and bar contain the same elements.\n";
  }

  return 0;
}