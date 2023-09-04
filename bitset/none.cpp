#include <bitset>
#include <iostream>

/**
 * 测试所有 bit 位是否全是 0
 *
 * @see count
 */

int main() {
  std::bitset<4> foo{"0000"};

  if (foo.none()) {
    std::cout << foo << " has no bits set.\n";
  } else {
    std::cout << foo << " has " << foo.count() << " bits set.\n";
  }

}
