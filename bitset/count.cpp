#include <bitset>
#include <string>
#include <iomanip>
#include <iostream>

/**
 * 判断有几位设置为 1
 */

int main() {

  std::bitset<4> bar{std::string{"0101"}};

  std::cout << bar << " has " << bar.count() << " ones "
            << (bar.size() - bar.count()) << " zeros"
            << '\n';

  return 0;
}