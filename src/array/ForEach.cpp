#include <iostream>

int main() {
  constexpr int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  // number是一个拷贝值
  for (auto number : fibonacci) // type is auto, so number has its type deduced
                                // from the fibonacci array
  {
    std::cout << number << ' ';
  }

  std::cout << '\n';
  // 最佳实践：在 for-each 循环中声明元素时，如果元素是非基本类型，则将其声明为引用或常数引用以提高性能。
  std::string array[]{"peter", "likes", "frozen", "yogurt"};
  // 当拷贝开销很大时，且多数情况我们需要访问元素本身，这时可以将其声明为引用类型。
  // 如果打算以只读的方式使用引用，最好加上const
  for (const auto &element :
       array) // The ampersand makes element a reference to the actual array
              // element, preventing a copy from being made
  {
    std::cout << element << ' ';
  }



  return 0;
}