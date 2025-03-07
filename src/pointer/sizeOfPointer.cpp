#include <iostream>

/**
 * 指针的大小取决于编译器和操作系统。
 * 指针的大小是指指针本身所占用的字节数，是固定的吗？不是的，它取决于编译器和操作系统。
 */
int main() // 假设为64位程序
{
    char* chPtr{};        // char 为1个字节
    int* iPtr{};          // int通常是4字节
    long double* ldPtr{}; // long doubles 通常是8字节或12字节

    std::cout << sizeof(chPtr) << '\n'; // 打印 8
    std::cout << sizeof(iPtr) << '\n';  // 打印 8
    std::cout << sizeof(ldPtr) << '\n'; // 打印 8

    return 0;
}