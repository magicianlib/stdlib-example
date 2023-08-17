#include <iostream>
#include <iterator>
#include <vector>

namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator out, UnaryPredicate _predicate) {
  while (first != last) {
    if (_predicate(*first)) {
      *out = *first;
      ++out;
    }
    ++first;
  }
  return out;
}
}

/**
 * 过滤偶数
 */
bool unary_predicate(int v) {
  return !(v % 2);
}

int main() {
  int ints[] = {1, 2, 3, 4, 5, 6, 7};

  std::vector<int> vt(std::distance(std::begin(ints), std::end(ints)));

  stdlib::copy_if(std::begin(ints), std::end(ints), vt.begin(), &unary_predicate);

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}