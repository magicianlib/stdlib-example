#include <iterator>
#include <vector>
#include <iomanip>
#include <iostream>

namespace stdlib {
template<typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1) {
    if (*first1 != *first2) {
      return false;
    }
    ++first1;
    ++first2;
  }
  return true;
}
}

int main() {
  int ints[] = {1, 2, 3, 6, 7};

  std::vector<int> vt(std::begin(ints), std::begin(ints) + 2);

  std::cout << std::boolalpha << stdlib::equal(std::begin(ints), std::end(ints), vt.begin()) << '\n';
}