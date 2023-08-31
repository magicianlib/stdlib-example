
/**
 * 检查一个范围是否被分区.
 * <br>
 * 该函数的作用是判断范围[first, last)是否被谓词 _predicate 分区.
 * 如果谓词 _predicate 将范围分成了两个不相交的子集, 其中第一个子集
 * 中的元素都满足谓词条件, 第二个子集中的元素都不满足谓词条件, 那么该
 * 范围就被视为被分区!
 */

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last && _predicate(*first)) { // 所有 _predicate 都为 true
    ++first;
  }

  // 走到这里说明当前 _predicate(*first) = false, 接下来的判断必须都为 false, 才表示被分区.
  while (first != last) {
    if (_predicate) { // 有为 true 的, 返回 false.
      return false;
    }
    ++first;
  }

  return true;
}
}