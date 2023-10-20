#include <algorithm>

/**
 * 将 [first, middle) 和 [middle, last) 位置互换并直接拷贝到 OutputIterator
 */
namespace stdlib {
template<typename ForwardIterator, typename OutputIterator>
void rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result) {
  std::copy(middle, last, result);
  std::copy(first, middle, result);
}
}  // namespace stdlib

#include <iostream>
#include <vector>

int main() {
  int ints[] = {10, 20, 30, 40, 50, 60, 70};

  std::vector<int> vt(7);

  stdlib::rotate_copy(ints, ints + 3, ints + 7, vt.begin());

  // print out content:
  std::cout << "vt contains:";
  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}