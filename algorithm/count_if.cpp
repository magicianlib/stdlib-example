#include <iterator>
#include <iostream>

namespace stdlib {
template<typename InputIterator, typename UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, UnaryPredicate _predicate) {

  typename std::iterator_traits<InputIterator>::difference_type count = 0;

  while (first != last) {
    if (_predicate(*first)) {
      ++count;
    }
    ++first;
  }
  return count;
}
}

bool count_condition(int val) {
  return !(val % 2);
}

int main() {

  int nums[] = {10, 20, 30, 30, 20, 10, 10, 20};

  long size = stdlib::count_if(std::begin(nums), std::end(nums), &count_condition);

  std::cout << "even appears " << size << " times.\n";

  return 0;
}