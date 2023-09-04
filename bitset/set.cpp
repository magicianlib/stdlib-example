#include <bitset>
#include <iostream>

/**
 * 将全部 bit 位 或 将指定 bit 位 设置为 1
 *
 * @see reset
 * @see flip
 */

int main() {

  std::bitset<4> foo{};

  foo.set(0);      // 0001

  std::cout << foo << '\n';

  foo.set();

  std::cout << foo << '\n'; // 1111

  return 0;
}