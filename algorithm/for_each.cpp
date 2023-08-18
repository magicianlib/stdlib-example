#include <memory>
#include <iostream>

namespace stdlib {
template<typename InputIterator, typename UnaryFunction>
UnaryFunction for_each(InputIterator first, InputIterator last, UnaryFunction fn) {
  while (first != last) {
    fn(*first);
    ++first;
  }
  return std::move(fn);
}
}

void fn(int i) {  // function:
  std::cout << ' ' << i;
}

struct StructFn {           // function object type:
  void operator()(int i) { std::cout << ' ' << i; }
};

int main() {
  std::vector<int> vt;
  vt.push_back(10);
  vt.push_back(20);
  vt.push_back(30);

  std::cout << "vt contains:";
  for_each(vt.begin(), vt.end(), &fn);
  std::cout << '\n';

  // or:
  std::cout << "vt contains:";
  for_each(vt.begin(), vt.end(), StructFn());
  std::cout << '\n';

  return 0;
}