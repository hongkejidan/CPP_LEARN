#include <iostream>

/**
 * 
 * 指针和引用都提供了间接访问另一个对象的方法。主要的区别在于，
 *  对于指针，我们需要显式地获取要指向的地址，并且显式地解引用指针来获取值。
 *  对于引用，地址和解引用都是隐式进行的。

    指针和引用之间还有一些值得一提的区别：

        引用必须被初始化，指针并不是必须初始化（但是你应该初始化）；
        引用不是对象，指针是对象；
        引用不能被重新设置（修改引用使其绑定到其他对象），指针则可以被修改指向其他对象；
        引用总是绑定到某个对象，指针可以不执行任何对象；
        引用是”安全“的（除了悬垂引用），指针则是危险的。
 * 
 * 
 */
int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    

    return 0;
}