#include <iostream>
#include <iterator>
#include <vector>

namespace stdlib {
template<typename OutputIterator, typename T, typename Size>
void fill_n(OutputIterator out, const T &init_val, Size n) {
  while (n > 0) {
    *out = init_val;
    ++out;
    --n;
  }
}
}

int main() {

  std::vector<int> vt(6, 20);

  stdlib::fill_n(vt.begin(), 10, 3);

  std::vector<int>::iterator it;
  for (it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
}