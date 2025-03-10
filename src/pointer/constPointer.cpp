#include <iostream>

int main()
{

    const int x { 5 }; // x 是 const
    // int* ptr { &x };   // 编译错误：&x是一个const int*，不能把const int* 转换为 int*

    const int y{ 6 };
    // 1. 声明一个指向常量的指针，需要在指针的数据类型前加上const 关键字
    const int *ptr2 { &y }; // okay: ptr is pointing to a "const int"
    // 2. 因为指针所指的值是数据类型是const int，所以不能通过指针来修改所指的值
    // *ptr2 = 6; // not allowed: we can't change a const value
    // 3. 但是指针本身不是const的，所以可以修改指针本身持有的地址，使其指向其他变量。
    int z{ 7 };
    ptr2 = &z; // okay: we can change the pointer itself
    // 4. 但是，指向常量的指针不能用于修改所指向的值，而不管该地址的对象是否定义为const。
    // *ptr2 = 8; // 编译错误，因为ptr2是指向常量的指针
    
    // 5. 指针自身也可以常量，一个指向常量的指针，在初始化之后是不可以被修改的。
    int a{ 5 };
    int* const ptr3{ &a }; // 这是一个指向非const int的const指针
    // ptr3 = &z; // 编译错误：ptr3 是一个const指针，不能改变它的值
    // 6. 但是可以通过指针来修改所指的值，因为ptr3指向的是一个非const int
    *ptr3 = 99; // 没问题。

    // 7. 如果我们想要一个指向常量的常量指针，那么两个const都需要加上。不能通过这个指针来修改所指向的值，也不能改变指针所指向的地址。只能通过解引用来访问所指向的值。
    const int* const ptr4{ &a }; // 这是一个指向常量的const指针
    // ptr4 = &z; // 编译错误：ptr4 是一个const指针，不能改变它的值
    // *ptr4 = 99; // 编译错误：ptr4 是一个指向常量的指针，不能通过ptr4来修改所指向的值
    std::cout << *ptr4 << std::endl;

    return 0;
}
