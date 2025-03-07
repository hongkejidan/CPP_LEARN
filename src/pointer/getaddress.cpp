#include <iostream>
#include <typeinfo>

/**
 *  取地址运算符 & 返回一个变量的地址。
    解引用运算符 * 返回一个对象。
 * & 符号在不同的语境下有不同的含义，比较容易混淆：
    当后面接着类型名时，&表示一个左值引用: int& ref；
    当用于一元表达式时，&表示取地址运算符: std::cout << &x.
    当用于二元表达式时，&是按位与操作: std::cout << x & y.


    对于一个给定地址，可以使用解引用运算符获取该地址保存的值（左值）。
    解引用和取地址是一对相反的操作，取地址获取对象的地址，解引用从地址获取对象。
 */
int main() {
    int x { 5 };
    // & 符号在这里表示取地址运算符，返回变量 x 的地址
    // &只能用于左值
    int *ptr { &x };
    std::cout << "x = " << x << '\n';
    std::cout << "ptr = " << ptr << '\n';
    std::cout << "&x = " << &x << '\n';
    std::cout << "&ptr = " << &ptr << '\n';

    // ptr 是一个指向 x 的指针，可以通过解引用操作符 * 来访问 x 的值
    std::cout << "*ptr = " << *ptr << '\n';

    // 取地址运算符&返回的是一个指针
    int y { 6 };
    std::cout << typeid(&y).name() << '\n'; // 输出Pi，表示指针，int类型。
    double z { 7.0 };
    std::cout << typeid(&z).name() << '\n'; // 输出Pd，表示指针，double类型。
    return 0;
}