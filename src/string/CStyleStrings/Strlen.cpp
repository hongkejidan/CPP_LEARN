#include <iostream>
#include <cstring>
#include <iterator> // for std::size


/**
 * strlen() 用于返回C风格字符串的长度(没有空字符)
 * 和 std::size()的区别：
 * strlen() 会返回空字符前所有字符的个数，而 std::size (或者sizeof() 技巧)则会返回整个数组的大小，不管数组内部存放了什么。
 */
int main()
{
    char name[20]{"Alex"}; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';
    std::cout << name << " has " << std::strlen(name) << " letters.\n";
    std::cout << name << " has " << std::size(name) << " characters in the array.\n"; // use sizeof(name) / sizeof(name[0]) if not C++17 capable

    return 0;
}