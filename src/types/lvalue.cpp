#include <iostream>
int main()
{
    int x { 5 };
    // ref 通过引用获取到了x的值
    int& ref { x };
    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';

    // 修改ref的值，x的值也会被修改
     x = 6; // x now has value 6

    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';


    ref = 7; // the object being referenced (x) now has value 7
    std::cout << "x = " << x << '\n';
    std::cout << "ref = " << ref << '\n';

    // 左值引用必须初始化
    // int& ref1; // error: ref1 must be initialized

    // 左值引用必须被绑定到一个可修改的左值上
    // int& ref2 { 4 }; // error: 4 is not an lvalue
    // int& ref3 { x + 2 }; // error: x + 2 is not an lvalue
    // const int y { 5 };
    // int& ref4 { y }; // error: y is not a modifiable lvalue

    // 引用不能为重新设置，即引用不能指向另一个对象
    int z { 5 };
    // ref5先引用了z，其值为5
    int& ref5 { z };
    std::cout << "z = " << z << " ref5 = " << ref5 << '\n';
    int w { 6 };
    // ref5又引用了w，其值为6，但是这里其实不是引用了w，而是将w的值赋给了ref5，此时z的值也被改变了
    ref5 = w;

    std::cout << "z = " << z << " ref5 = " << ref5 << '\n';

    // 引用销毁，不会影响到引用的对象
    int a { 5 };
    {
        int& ref6 { a };
        std::cout << "a = " << a << " ref6 = " << ref6 << '\n';
    }
    std::cout << "a = " << a << '\n';

    // 引用悬垂：当一个对象先于它的引用被销毁，则其引用此时会绑定到一个已经不存在的对象。
    // 此时该引用会成为一个悬垂引用。访问悬垂引用会导致未定义行为。
    // 引用不是对象，不需要存在或占用存储空间。
    return 0;
}