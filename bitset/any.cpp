#include <bitset>
#include <string>
#include <iomanip>
#include <iostream>

/**
 * 任何一个位置设置 1 即为 true
 */

int main() {

  std::bitset<4> foo{std::string{"0000"}};
  std::bitset<4> bar{std::string{"0001"}};

  std::cout << std::boolalpha;
  std::cout << foo.any() << '\n';
  std::cout << bar.any() << '\n';
  std::cout << std::noboolalpha;

  return 0;
}