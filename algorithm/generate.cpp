namespace stdlib {
template<typename ForwardIterator, typename GeneratorFn>
void generate(ForwardIterator first, ForwardIterator last, GeneratorFn fn) {
  while (first != last) {
    *first = fn(); // 左值运算, 需要使用 ForwardIterator
    ++first;
  }
}
}