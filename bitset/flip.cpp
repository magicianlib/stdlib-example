#include <bitset>
#include <iostream>

/**
 * 翻转全部 bit 位 或 指定 bit 位
 *
 * @see set
 * @see reset
 */

int main() {

  std::bitset<4> foo{"1010"};

  foo.flip();  // 0101

  std::cout << foo << '\n';

  foo.flip(1); // 0111

  std::cout << foo << '\n';

  return 0;
}