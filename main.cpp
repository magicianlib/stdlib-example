#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <iterator>
#include <functional>

template<typename T, std::size_t N>
void copy_array(const T (&src)[N], T (&dst)[N]) {
  for (std::size_t i = 0; i < N; ++i) {
    dst[i] = src[i];
  }
}

template<typename T>
void copy_array(const T (&src)[], T (&dst)[]) {
  for (std::size_t i = 0; i < src.size(); ++i) {
    dst[i] = src[i];
  }
}

int main() {

  int src_arr[5] = {1, 2, 3, 4, 5};
  int dst_arr[5] = {6, 7, 8, 9, 10};

  copy_array<int, 5>(src_arr, dst_arr);

  // 省略数组大小
  copy_array<int>(src_arr, dst_arr);

  // 同时省略类型与大小
  copy_array(src_arr, dst_arr);

  std::vector<std::string> a1 = {"apple", "banana", "cherry"};
  std::vector<std::string> a2 = {"apple", "bn", "ch"};

  std::vector<std::string>::iterator it1;
  std::vector<std::string>::iterator it2;

  std::tie(it1, it2) = std::mismatch(a1.begin(), a1.end(), a2.begin());

  std::cout << *it1 << '\n';
  std::cout << *it2 << '\n';

  return 0;
}