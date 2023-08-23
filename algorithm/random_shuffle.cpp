#include <iterator>
#include <algorithm>

namespace stdlib {
/*template<typename RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);*/

template<typename RandomAccessIterator, typename RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator &_generator) {
  typedef typename std::iterator_traits<RandomAccessIterator>::difference_type DifferenceTye;
  DifferenceTye i;
  DifferenceTye n = (last - first);
  for (i = (n - 1); i > 0; --i) {
    std::swap(first[i], first[_generator(i + 1)]);
  }
}
}

#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

int my_random(int i) {
  return std::rand() % i;
}

int main() {
  std::srand(unsigned(std::time(nullptr)));

  std::vector<int> vt;

  for (int i = 1; i < 10; ++i) {
    vt.push_back(i); // 1 2 3 4 5 6 7 8 9
  }

  // using built-in random generator:
  std::random_shuffle(vt.begin(), vt.end());

  // using my_random
  stdlib::random_shuffle(vt.begin(), vt.end(), my_random);

  std::cout << "vt contains: " << '\n';

  for (std::vector<int>::iterator it = vt.begin(); it != vt.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}