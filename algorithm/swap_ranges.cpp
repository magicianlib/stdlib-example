#include <utility>

template<typename T>
void swap(T &a, T &b) {
  T c(std::move(a));
  a = std::move(b);
  b = std::move(c);
}

namespace stdlib {
template<typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2) {
  while (first1 != last1) {
    swap(*first1, *first2);
    ++first1;
    ++first2;
  }
}
}  // namespace stdlib

#include <iostream>
#include <vector>

int main() {
  std::vector<int> foo(5, 10);  // foo: 10 10 10 10 10
  std::vector<int> bar(5, 33);  // bar: 33 33 33 33 33

  stdlib::swap_ranges(foo.begin() + 1, foo.end() - 1, bar.begin());

  // print out results of swap:
  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';
  return 0;
}