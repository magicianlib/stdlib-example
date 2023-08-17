#include <iterator>
#include <iostream>

namespace stdlib {
template<typename InputIterator, typename T>
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const T &val) {
  typename std::iterator_traits<InputIterator>::difference_type count = 0;
  while (first != last) {
    if (*first == val) {
      ++count;
    }
    ++first;
  }
  return count;
}
}

int main() {

  int nums[] = {10, 20, 30, 30, 20, 10, 10, 20};

  long size = stdlib::count(std::begin(nums), std::end(nums), 10);

  std::cout << "10 appears " << size << " times.\n";

  return 0;
}