#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace stdlib {
template<typename InputIterator, typename OutputIterator>
OutputIterator move(InputIterator first, InputIterator last, OutputIterator out) {
  while (first != last) {
    *out = std::move(*first);
    ++first;
    ++out;
  }
  return out;
}
}  // namespace stdlib

int main() {
  std::vector<std::string> foo = {"air", "water", "fire", "earth"};
  std::vector<std::string> bar(4);

  // moving ranges:
  std::cout << "Moving ranges...\n";
  stdlib::move(foo.begin(), foo.begin() + 4, bar.begin());

  std::cout << "foo contains " << foo.size() << " elements:";
  std::cout << " (each in an unspecified but valid state)";
  std::cout << '\n';

  std::cout << "bar contains " << bar.size() << " elements:";
  for (std::string &x : bar) {
    std::cout << " [" << x << "]";
  }
  std::cout << '\n';

  // moving container:
  std::cout << "Moving container...\n";
  foo = std::move(bar);

  std::cout << "foo contains " << foo.size() << " elements:";
  for (std::string &x : foo) {
    std::cout << " [" << x << "]";
  }
  std::cout << '\n';

  std::cout << "bar is in an unspecified but valid state";
  std::cout << '\n';
  return 0;
}