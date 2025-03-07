#include <iostream>

int main() {
    int* ptr {}; // 此时，ptr 是一个空指针
    // std::cout << "Value of ptr: " << *ptr << std::endl; // 对空指针解引用会导致未定义行为！！！

    // 可以使用赋值来改变指针所指向的对象
    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    // 当需要空指针字面量用于指针的初始化、赋值或作为参数时，可以使用 nullptr。
    int* ptr2 { nullptr }; // ptr2 is initialized to a null pointer


    // 检查空指针
    if (ptr == nullptr)
        std::cout << "ptr is a null pointer\n";
    else
        std::cout << "ptr is not a null pointer\n";

    std::cout << "ptr2 is a " << (ptr2 == nullptr ? "null pointer\n" : "not null pointer\n");

    return 0;
}