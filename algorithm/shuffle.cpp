#include <algorithm>
#include <random>

namespace stdlib {
template<typename RandomAccessIterator, typename RandomEngine>
void shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomEngine &&_engine) {
  for (auto i = (last - first); i > 0; --i) {
    std::uniform_int_distribution<int> dis(0, i);
    std::swap(first[i], first[dis(_engine)]);
  }
}
}

#include <array>
#include <chrono>
#include <iostream>

int main() {
  std::array<int, 5> foo = {1, 2, 3, 4, 5};

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  stdlib::shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));

  std::cout << "foo: " << '\n';
  for (int &item : foo) {
    std::cout << item << ' ';
  }

  return 0;
}