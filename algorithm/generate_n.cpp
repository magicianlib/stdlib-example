#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <functional>

namespace stdlib {
template<typename ForwardIterator, typename Size, typename GeneratorFn>
void generate_n(ForwardIterator first, Size sz, GeneratorFn fn) {
  while (sz > 0) {
    *first = fn();
    ++first;
    --sz;
  }
}
}

static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
static std::uniform_int_distribution<int> distribution(0, 10);

int main() {
  std::vector<int> vt(10);

  auto fc = [&]() -> int { return distribution(generator); };

  stdlib::generate_n(vt.begin(), vt.size(), fc);

  for (const auto &item : vt) {
    std::cout << item << ' ';
  }

  std::cout << '\n';

  return 0;
}