namespace stdlib {
template<typename InputIterator, typename T>
void replace(InputIterator first, InputIterator last, const T &old_val, const T &new_val) {
  while (first != last) {
    if (*first == old_val) {
      *first = new_val;
    }
    ++first;
  }
}
}

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};
  std::vector<int> vt(myints, myints + 8);            // 10 20 30 30 20 10 10 20

  std::replace(vt.begin(), vt.end(), 20, 99); // 10 99 30 30 99 10 10 99

  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}