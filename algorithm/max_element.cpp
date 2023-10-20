#include <iostream>

namespace stdlib {
template<typename InputIterator>
InputIterator max_element(InputIterator first, InputIterator last) {
  if (first == last) {
    return first;
  }

  InputIterator largest = first;
  while (++first != last) {  // skip first
    if (*largest < *first) {
      largest = first;
    }
  }
  return largest;
}

template<typename InputIterator, typename Compare>
InputIterator max_element(InputIterator first, InputIterator last, Compare _compare) {
  if (first == last) {
    return first;
  }

  InputIterator largest = first;
  while (++first != last) {  // skip first
    if (_compare(*largest, *first)) {
      largest = first;
    }
  }
  return largest;
}
}  // namespace stdlib

bool compare(int i, int j) {
  return i < j;
}

struct Functor {
  bool operator()(int i, int j) { return i < j; }
} functor;

int main() {
  int ints[] = {3, 7, 2, 5, 6, 4, 9};

  // using default comparison:
  std::cout << "The largest element is " << *stdlib::max_element(ints, ints + 7) << '\n';

  // using compare compare as comp:
  std::cout << "The largest element is " << *stdlib::max_element(ints, ints + 7, &compare) << '\n';

  // using object functor as comp:
  std::cout << "The largest element is " << *stdlib::max_element(ints, ints + 7, functor) << '\n';

  return 0;
}