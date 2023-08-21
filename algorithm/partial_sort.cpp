#include <algorithm>
#include <numeric>
#include <iterator>
#include <random>
#include <vector>
#include <iostream>

/**
 * 重新排列范围 [first,last) 中的元素, 使得 middle 之前的元素是整个范围中最小的元素.
 * 并按升序排序, 而其余元素没有任何特定顺序。
 */

namespace stdlib {
template<typename RandomAccessIterator>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);

template<typename RandomAccessIterator, typename Compare>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare _compare);
}

bool int_compare(int x, int y) {
  return (x < y);
}

int main() {

  std::vector<int> vt(100);
  std::iota(vt.begin(), vt.end(), 1);

  // 随机洗牌
  std::shuffle(vt.begin(), vt.end(), std::mt19937(std::random_device()()));

  // using default comparison (operator <):
  std::partial_sort(vt.begin(), vt.begin() + 50, vt.end());

  // using function as comp
  // std::partial_sort(vt.begin(), vt.begin() + 50, vt.end(), &int_compare);

  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}