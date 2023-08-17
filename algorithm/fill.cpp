#include <iostream>
#include <iterator>
#include <vector>

namespace stdlib {
template<typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T &init_val) {
  while (first != last) {
    *first = init_val;
    ++first;
  }
}
}

int main() {

  std::vector<int> vt(6, 20);

  stdlib::fill(vt.begin() + 3, vt.end(), 10);

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}