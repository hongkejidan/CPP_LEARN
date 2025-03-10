
#include <iostream>
#include <string>

void printByValue(std::string val) // 函数的参数是一个值，该值是通过复制传递给函数的
{
    std::cout << val << '\n'; // 通过值打印字符串
}

void printByReference(const std::string &ref) // 函数的参数是一个引用，该引用指向传递给函数的值
{
    std::cout << ref << '\n'; // 通过引用打印字符串
}

void printByAddress(const std::string *ptr) // 函数的参数是一个指针，该指针指向传递给函数的值
{
    std::cout << *ptr << '\n'; // 通过指针打印字符串
}

int main()
{
    std::string str{"Hello, world!"};

    printByValue(str);     // 通过值传递str，会复制str
    printByReference(str); // 通过引用传递str，不会复制str
    printByAddress(&str);  // 通过指针传递str，不会复制str

    return 0;
}