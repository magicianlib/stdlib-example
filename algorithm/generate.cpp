#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <functional>

namespace stdlib {
template<typename ForwardIterator, typename GeneratorFn>
void generate(ForwardIterator first, ForwardIterator last, GeneratorFn fn) {
  while (first != last) {
    *first = fn(); // 左值运算, 需要使用 ForwardIterator
    ++first;
  }
}
}

static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
static std::uniform_int_distribution<int> distribution(0, 10);

int main() {
  std::vector<int> vt(10);

  auto fc = [&]() -> int { return distribution(generator); };

  stdlib::generate(vt.begin(), vt.end(), fc);

  for (const auto &item : vt) {
    std::cout << item << ' ';
  }

  std::cout << '\n';

  return 0;
}