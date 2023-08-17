#include <iostream>
#include <array>

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
bool any_of(InputIterator first, InputIterator last, UnaryPredicate _predicate) {
  while (first != last) {
    if (_predicate(*first)) {
      return true;
    }
    ++first;
  }
  return false;
}
}

bool less(int v) {
  return v < 0;
}

int main() {
  std::array<int, 7> foo = {0, 1, -1, 3, -3, 5, -5};

  if (stdlib::any_of(foo.begin(), foo.end(), &less)) {
    std::cout << "There are negative elements in the range.\n";
  }
}