namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename T>
OutputIterator replace_copy(
    InputIterator first, InputIterator last, OutputIterator result, const T &old_val, const T &new_val) {
  while (first != last) {
    *result = (*first == old_val) ? new_val : *first;
    ++result;
  }
  return result;
}
}  // namespace stdlib

#include <algorithm>  // std::replace_copy
#include <iostream>   // std::cout
#include <vector>     // std::vector

int main() {
  int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};

  std::vector<int> myvector(8);
  std::replace_copy(myints, myints + 8, myvector.begin(), 20, 99);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}