#include <bitset>
#include <iostream>

int main() {

  std::bitset<4> foo{0xF}; // 16 进制 15

  std::cout << foo.to_string() << '\n'; // 1111 二进制形式
  std::cout << foo.to_ulong() << '\n';  // 15
  std::cout << foo.to_ullong() << '\n'; // 15

  return 0;
}