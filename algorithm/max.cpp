#include <initializer_list>
#include <iostream>

namespace stdlib {
template<typename T>
const T &max(const T &t1, const T &t2) {
  return (t1 < t2) ? t2 : t1;
}

template<typename T, typename Compare>
const T &max(const T &t1, const T &t2, Compare _compare) {
  return _compare(t1, t2) ? t2 : t1;
}

template<typename T>
T max(std::initializer_list<T> list) {
  const T *begin = list.begin();
  const T *end = list.end();

  T max = *list.begin();

  while (begin != end) {
    if ((max) < (*begin)) {
      max = *begin;
    }
    ++begin;
  }
  return max;
}

template<typename T, typename Compare>
T max(std::initializer_list<T> list, Compare _compare) {
  const T *begin = list.begin();
  const T *end = list.end();

  T max = *list.begin();

  while (begin != end) {
    if (_compare(max, *begin)) {
      max = *begin;
    }
    ++begin;
  }
  return max;
}
}  // namespace stdlib

int main() {
  std::cout << "max(1,2)==" << stdlib::max(1, 2) << '\n';
  std::cout << "max(2,1)==" << stdlib::max(2, 1) << '\n';
  std::cout << "max('a','z')==" << stdlib::max('a', 'z') << '\n';
  std::cout << "max(3.14,2.73)==" << stdlib::max(3.14, 2.73) << '\n';

  std::initializer_list<int> list{1, 2, 4, 3, 7, 9, 10};
  std::cout << "max(std::initializer_list<int>)==" << stdlib::max(list) << '\n';

  return 0;
}