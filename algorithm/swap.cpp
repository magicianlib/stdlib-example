#include <utility>

namespace stdlib {
template<typename T>
void swap(T &a, T &b) {
  T c(std::move(a));
  a = std::move(b);
  b = std::move(c);
}

template<typename T, std::size_t N>
void swap(T (&a)[N], T (&b)[N]) {
  for (int i = 0; i < N; ++i) {
    swap(a[i], b[i]);
  }
}
}  // namespace stdlib

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int arr1[] = {1, 2, 3};
  int arr2[] = {4, 5, 6};
  stdlib::swap(arr1, arr2);

  int x = 10, y = 20;  // x:10 y:20
  stdlib::swap(x, y);  // x:20 y:10

  std::vector<int> foo(4, x), bar(6, y);  // foo:4x20 bar:6x10
  stdlib::swap(foo, bar);                 // foo:6x10 bar:4x20

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}