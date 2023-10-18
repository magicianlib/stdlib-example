#include <bitset>
#include <iostream>

[[maybe_unused]] constexpr std::uint8_t mask0{1 << 0};  // 0b0000'0001
[[maybe_unused]] constexpr std::uint8_t mask1{1 << 1};  // 0b0000'0010
[[maybe_unused]] constexpr std::uint8_t mask2{1 << 2};  // 0b0000'0100
[[maybe_unused]] constexpr std::uint8_t mask3{1 << 3};  // 0b0000'1000
[[maybe_unused]] constexpr std::uint8_t mask4{1 << 4};  // 0b0001'0000
[[maybe_unused]] constexpr std::uint8_t mask5{1 << 5};  // 0b0010'0000
[[maybe_unused]] constexpr std::uint8_t mask6{1 << 6};  // 0b0100'0000
[[maybe_unused]] constexpr std::uint8_t mask7{1 << 7};  // 0b1000'0000

int main() {
  std::bitset<8> flag{0b0000'0101};
  std::cout << flag << " default flag\n";

  std::cout << (flag |= mask1) << " turn on mask1" << '\n';
  std::cout << (flag &= ~mask0) << " turn off mask0" << '\n';
  std::cout << (flag |= (mask0 | mask5)) << " turn on mask0 mask5" << '\n';
  std::cout << (flag &= ~(mask2 | mask5)) << " turn off mask2 mask5" << '\n';
  std::cout << (flag ^= mask7) << " flipping mask7" << '\n';
  std::cout << (flag ^= mask7) << " flipping mask7 again" << '\n';

  return 0;
}