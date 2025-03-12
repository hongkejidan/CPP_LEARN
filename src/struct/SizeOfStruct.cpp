#include <iostream>

struct Foo
{
    short a {}; // 长度为2字节
    int b {};  // 长度为4字节
    double c {}; // 长度为8字节
};

struct Foo1
{
    short a{}; // 长度为2字节
    short qq{}; // 长度为2字节   // note: qq is defined here
    int b{};   // 长度为4字节
    double c{}; // 长度为8字节
};

struct Foo2
{
    short a{}; 
    int b{};
    double c{};
    short qq{}; // note: qq is defined here
};

int main()
{
    // 由于结构体填充，结构体的大小可能会大于所有成员大小之和。
    // 通过计算每个成员的大小来计算结构体的大小，计算Foo大小为2+4+8=14字节，但是实际上Foo的大小为16字节。
    std::cout << "The size of Foo is " << sizeof(Foo) << '\n';
    // 计算Foo1大小为2+2+4+8=16字节，实际上也是16字节。
    std::cout << "The size of Foo1 is " << sizeof(Foo1) << '\n';
    // 计算Foo2大小为2+4+8+2=16字节，实际上是24字节。
    std::cout << "The size of Foo2 is " << sizeof(Foo2) << '\n';

    return 0;
}