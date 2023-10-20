#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/**
 * 从迭代器中找到第 n 小的元素 K, 并将 K 移动到迭代器中第 n 的位置处. 不仅如此, 整个迭代器经过 nth_element
 * 函数处理后, 所有位于 K 之前的元素都比 K 小(或等于K). 所有位于 K 之后的元素都比 K 大(或等于K).
 * <br>
 * 该函数与完成排序的区别在于:
 *  只关注第 n 个元素大小, 纸包装小于该值的元素在其左边, 大于等于的在其右边, 但并不保证其完全有序.
 */

namespace stdlib {
template<typename RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last) {
  if (first == last || nth == last) {  // 如果不存在元素或 nth 是尾迭代器, 不做处理
    return;
  }

  // TODO...
}
}  // namespace stdlib

bool compare(int x, int y) {
  return (x < y);
}

int main() {
  std::vector<int> vt(10);
  std::iota(vt.begin(), vt.end(), 1);

  std::vector<int>::iterator it;

  // 随机排序
  std::random_shuffle(vt.begin(), vt.end());

  std::cout << "vt contains random_shuffle: " << '\n';
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  // use default comparison (operator<)
  std::nth_element(vt.begin(), vt.begin() + 5, vt.end());

  // use compare fn
  std::nth_element(vt.begin(), vt.begin() + 5, vt.end(), &compare);

  std::cout << "vt contains nth_element: " << '\n';
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}