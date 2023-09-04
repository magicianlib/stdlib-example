#include <bitset>
#include <iomanip>
#include <iostream>

/**
 * 测试指定 bit 位是否为 1
 */

int main() {

  std::bitset<4> foo{"1010"};

  std::cout << "foo contains:\n";
  std::cout << std::boolalpha;

  for (int i = (foo.size() - 1); i >= 0; --i) {
    std::cout << foo.test(i) << ' ';
  }

  return 0;
}