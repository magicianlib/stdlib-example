#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {


  std::vector<int> foo = {0, 1, -1, 3, -3, 5, -5};

  std::vector<int>::difference_type diff = std::distance(foo.cbegin(), foo.cend());

  std::cout << diff << '\n';

  std::vector<int>::iterator it;

  it = foo.begin();
  std::cout << *it << '\n';

  std::advance(it, 1);
  std::cout << *it << '\n';

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
