#include <bitset>
#include <cstddef>
#include <iostream>

std::ostream &operator<<(std::ostream &out, std::byte b) {
  return out << std::bitset<8>(std::to_integer<int>(b));
}

struct User {
  static inline int example_val{100};

private:
  std::string username{};
  int age{};
  std::string mobile_phone{};

public:
  const std::string &get_username() const { return username; }
  void set_username(const std::string &_username) { username = _username; }
  int get_age() const { return age; }
  void set_age(int _age) { age = _age; }
  const std::string &get_mobile_phone() const { return mobile_phone; }
  void set_mobile_phone(const std::string &_mobile_phone) { mobile_phone = _mobile_phone; }
};

constexpr int user_addr{10};

User get_user() {
  return User{};
}

int main() {
  int b[10]{1, 2};

  std::byte data[10]{std::byte{1}};

  return 0;
}