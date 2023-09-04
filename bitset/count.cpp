#include <bitset>
#include <string>
#include <iomanip>
#include <iostream>

/**
 * 判断有几个 bit 位设置为 1
 *
 * @see none
 */

int main() {

  std::bitset<4> bar{std::string{"0101"}};

  std::cout << bar << " has " << bar.count() << " ones "
            << (bar.size() - bar.count()) << " zeros"
            << '\n';

  return 0;
}