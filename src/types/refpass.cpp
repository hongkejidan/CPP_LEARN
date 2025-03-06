#include <iostream>
#include <string>

// 如果形参类型是std::string，那么实参会被拷贝到形参。
// 如果形参类型是std::string&，那么实参不会被拷贝到形参，而是实参的引用被传递给形参。
void printValue(std::string& value) {
    std::cout << value << '\n';

}

// 使用引用传递，可以修改实参的值
// 由于形参要求是引用，所以实参必须是左值，而不能是const变量或字面量
void addOne(int& x) {
    x += 1;
}

// 使用const引用传递，可以避免拷贝，同时也可以接受const变量和字面量，但是不能修改实参的值。
void print(const int& x) {
    std::cout << x << '\n';
}

/**
 * 何时按引用传递？
 * 对于拷贝开销不大的对象，拷贝传递的开销和引用绑定的开销可能差不多，所以应该使用按值传递，以便编译器生成更高效的代码；
 *  对于拷贝开销很大的对象，拷贝开销占据了大头，所以应该使用按值传递（const）来避免拷贝。
 */
int main() {
    std::string str { "Hello, world!纽币" };
    printValue(str);

    int x { 5 };
    addOne(x);
    std::cout << x << '\n';

    // const int y { 5 };
    // addOne(y); // error: y is const
    // addOne(4); // error: 4 is not an lvalue
    int z { 5 };
    const int w { 6 };
    const int& ref { z };
    print(z);
    print(w);
    print(ref);
    print(9);

    return 0;
}