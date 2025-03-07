#include <iostream>

int main()
{
    // 普通变量
    int x{5};
    // 指向变量的左值引用
    int &ref{x};
    // 一个指针，但是没有初始化，叫做野指针。
    int* ptr;

    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';
    std::cout << "ptr = " << ptr << '\n';


    int* ptr1; // 一个未初始化的指针，野指针
    int* ptr2{}; // 一个空指针
    int* ptr3{&x}; // 指针，初始化为变量x的地址

    std::cout << "ptr1 = " << ptr1 << '\n';
    std::cout << "ptr2 = " << ptr2 << '\n';
    std::cout << "ptr3 = " << ptr3 << '\n';
    // 使用解引用操作符 * 通过指针ptr3来访问 x 的值
    std::cout << "*ptr3 = " << *ptr3 << '\n';

    // 指针的类型必须匹配指向对象的类型
    int i{ 5 };
    double d{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    // int* iPtr2 { &d };   // not okay: a pointer to an int can't point to a double
    double* dPtr{ &d };  // ok: a pointer to a double can point to a double object
    // double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int

    /**
     * 在使用指针时，如果不同时使用解引用的时候，我们使用的是指针存放的地址。修改该地址就可以改变指针的指向 (ptr = &y)。
        当对指针应用解引用时(*ptr)，我们访问的则是指针所指的对象。修改(*ptr = 6;) 它可以改变该变量的值。
     */
    int* ptr4{ &x }; // ptr4 points to x
    std::cout << "x = " << x << '\n';
    std::cout << "*ptr4 = " << *ptr4 << '\n';
    // 修改ptr4的指向对象
    int y{ 6 };
    ptr4 = &y; // ptr4 now points to y
    std::cout << "*ptr4 = " << *ptr4 << '\n';

    // 使用指针修改变量的值
    *ptr4 = 7; // y is now 7
    std::cout << "y = " << y << '\n';

    return 0;
}