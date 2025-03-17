#include <iostream>

int main() {
  std::cout << "Enter a positive integer: ";
  long long length{};
  std::cin >> length;

  int *array{new int[length]{}}; // 使用数组 new，注意这里的length不需要是常数！

  std::cout << "I just allocated an array of integers of length " << length
            << '\n';

  array[0] = 5; // 元素 0 赋值为 5

  delete[] array; // 使用数组 delete 释放内存

  // 此处不需要将 array 设置为 nullptr/0 因为它马上就会离开作用域被销毁

  return 0;
}