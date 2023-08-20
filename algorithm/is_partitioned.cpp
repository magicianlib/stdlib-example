
/**
 * 如果所有的 _predicate 都在 !_predicate 之前则返回 true.
 */

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last && _predicate(*first)) { // 所有 _predicate 都为 true
    ++first;
  }

  // 走到这里说明当前 _predicate(*first) = false, 接下来的判断必须都为 false, 结果才为 true.
  while (first != last) {
    if (_predicate) { // 有为 true 的, 返回 false.
      return false;
    }
    ++first;
  }

  return true;
}
}