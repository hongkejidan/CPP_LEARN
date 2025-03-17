// 内存泄漏问题

// 1. 指向动态分配内存的指针超出作用域前没有delete释放。
// 这个函数动态分配了一个整数，但是没有delete释放它，
// 因为当函数结束时，ptr离开作用域，ptr是保存动态分配的整数地址的唯一变量，
// 当其销毁时，对动态分配的内存没有更多的引用，这意味着程序丢失了动态分配的内存的地址。所以无法再删除这个动态分配的整数。
void doSomething() { int *ptr{new int}; }

int main() {
  // 其他会导致内存泄漏的操作：
  // 2. 持有动态分配内存的指针，被分配了另一个值
  int value = 5;
  int *ptr{new int{}}; // 分配了内存
  delete ptr;          // 将内存释放，防止内存泄漏
  ptr = &value;        // 指向新地址。如果不先delete，会引发内存泄漏

  // 3. 与2类似，重复分配内存也会导致内存泄漏。
  int *ptr2{new int{}};
  delete ptr2;      // 释放内存，防止内存泄漏。
  ptr2 = new int{}; // 重新分配内存前要delete
}