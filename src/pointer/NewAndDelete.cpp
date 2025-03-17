#include <iostream>

int main() {
  int *ptr{new int}; // 动态分配一个整型
  *ptr = 7;          // 向该内存赋一个值

  delete ptr; // 内存还给操作系统，ptr现在是悬垂指针

  std::cout << *ptr << '\n'; // 间接访问悬垂指针会导致未定义行为
  //   delete ptr;        // 报错 再次释放已经被释放的内存也会导致未定义行为
  // "最佳实践"
  // 将已删除的指针设置为nullptr，除非它们随后将立即超出作用域。
  ptr = nullptr;

  // new运算符可能执行失败，当系统没有可用内存时
  // 处理方式：如果无法分配内存，可以通过在new和分配类型之间添加常量
  // std::nothrow 来实现
  double *ptr2{new (std::nothrow) double};
  *ptr2 = 999.009;
  std::cout << *ptr2 << std::endl;
  delete ptr2;
  ptr2 = nullptr;
  // 如果是个空指针，我们可以经过判断重新给它分配内存。
  if (!ptr2) {
    ptr2 = new double;
  }




  return 0;
}