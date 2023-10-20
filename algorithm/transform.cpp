
namespace stdlib {
template<typename InputIterator, typename OutputIterator, typename UnaryOperator>
OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperator _operator) {
  while (first != last) {
    *result = _operator(*first);
    ++first;
    ++result;
  }
}

template<typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperator>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result,
    BinaryOperator _operator) {
  while (first1 != last1) {
    *result = _operator(*first1, *first2++);
    ++first1;
    ++result;
  }
}
}  // namespace stdlib

#include <iostream>
#include <vector>

int op_increase(int i) {
  return ++i;
}

int main() {
  std::vector<int> foo;
  std::vector<int> bar;

  // set some values:
  for (int i = 1; i < 6; i++) {
    foo.push_back(i * 10);
  }  // foo: 10 20 30 40 50

  bar.resize(foo.size());  // allocate space

  stdlib::transform(foo.begin(), foo.end(), bar.begin(), op_increase);
  // bar: 11 21 31 41 51

  // std::plus adds together its two arguments:
  stdlib::transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
  // foo: 21 41 61 81 101

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it) {
    std::cout << ' ' << *it;
  }
  std::cout << '\n';

  return 0;
}