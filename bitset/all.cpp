#include <bitset>
#include <string>
#include <iomanip>
#include <iostream>

/**
 * 所有位置是否全部设置为 1
 */

int main() {

  std::bitset<4> foo{std::string{"0111"}};
  std::bitset<4> bar{std::string{"1111"}};

  std::cout << std::boolalpha;
  std::cout << foo.all() << '\n';
  std::cout << bar.all() << '\n';
  std::cout << std::noboolalpha;

  return 0;
}