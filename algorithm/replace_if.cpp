namespace stdlib {
template<typename InputIterator, typename UnaryPredicate, typename T>
void replace_if(InputIterator first, InputIterator last, UnaryPredicate _predicate, const T &new_val) {
  while (first != last) {
    if (_predicate(*first)) {
      *first = new_val;
    }
    ++first;
  }
}
}  // namespace stdlib

#include <algorithm>  // std::replace_if
#include <iostream>   // std::cout
#include <vector>     // std::vector

bool is_odd(int i) {
  return ((i % 2) == 1);
}

int main() {
  std::vector<int> vt;

  // set some values:
  for (int i = 1; i < 10; i++) {
    vt.push_back(i);
  }  // 1 2 3 4 5 6 7 8 9

  std::replace_if(vt.begin(), vt.end(), is_odd, 0);  // 0 2 0 4 0 6 0 8 0

  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}