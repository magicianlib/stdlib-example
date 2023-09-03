#include <bitset>
#include <iostream>

int main() {

  std::bitset<8> foo{}; // 8位默认全部填充0
  std::bitset<8> bar{0xF}; // 十六进制形式 15
  std::bitset<8> baz{std::string("111")}; // 使用 string 构造二进制形式 7

  std::cout << foo << '\n';
  std::cout << bar << '\n';
  std::cout << baz << '\n';
  std::cout << '\n';

  foo = 0'10;  // 八进制形式 8
  bar = 0b111; // 直接使用二进制形式 7

  std::cout << foo << '\n';
  std::cout << bar << '\n';

  return 0;
}