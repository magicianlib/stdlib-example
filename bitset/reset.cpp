#include <bitset>
#include <iostream>

/**
 * 将全部或指定 bit 位设置为 0
 *
 * @see set
 * @see flip
 */

int main() {

  std::bitset<4> foo{"1111"};

  foo.reset(1); // 1101

  std::cout << foo << '\n';

  foo.reset(); // 0000

  std::cout << foo << '\n';

  return 0;
}