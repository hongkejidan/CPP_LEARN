#include <iostream>
#include <cstddef> // for NULL
int main()
{
    int *ptr{}; // 此时，ptr 是一个空指针
    // std::cout << "Value of ptr: " << *ptr << std::endl; // 对空指针解引用会导致未定义行为！！！

    // 可以使用赋值来改变指针所指向的对象
    int x{5};
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    // 当需要空指针字面量用于指针的初始化、赋值或作为参数时，可以使用 nullptr。
    int *ptr2{nullptr}; // ptr2 is initialized to a null pointer

    // 检查空指针
    if (ptr == nullptr)
        std::cout << "ptr is a null pointer\n";
    else
        std::cout << "ptr is not a null pointer\n";

    std::cout << "ptr2 is a " << (ptr2 == nullptr ? "null pointer\n" : "not null pointer\n");

    // 使用指针之前记得判空，可以避免对空指针的引用
    // Assume ptr is some pointer that may or may not be a null pointer
    if (ptr)                       // if ptr is not a null pointer
        std::cout << *ptr << '\n'; // okay to dereference
    else
        // do something else that doesn't involve dereferencing ptr (print an error message, do nothing at all, etc...)
        std::cout << "ptr is a null pointer\n";
    // 还有一个名为NULL 的预处理器宏(在<cstddef> 头文件中定义)。这个宏是从C语言中继承的，在C语言中它通常用于指示空指针。
    // 但是在C++中，我们更倾向于使用nullptr，因为nullptr 是一个真正的空指针常量，而NULL 只是一个整数0。
    double* ptr3{NULL}; // ptr3 is a null pointer
    double* ptr4;
    ptr4 = NULL; // ptr4 is a null pointer

    // 指针和引用都使我们能够间接访问其他对象。
    // 指针还有其他功能，可以改变它们所指向的对象，也可以指向null。
    // 然而，这些指针功能本身也很危险：空指针有被解引用的风险，而改变指针所指向的对象的能力也使其更容易导致悬垂指针的出现：
    int* ptr5 { };

    {
        int x{ 5 };
        ptr5 = &x; // 将指针指向一个即将被销毁的对象（如果是引用则不可能这么做）
    } // ptr 现在是悬垂指针
    std::cout << *ptr5 << '\n'; // 虽然这里可能会输出5，但是这是未定义行为，因为ptr5是一个悬垂指针

    return 0;
}