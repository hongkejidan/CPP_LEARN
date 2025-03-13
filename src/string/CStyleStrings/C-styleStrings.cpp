#include <iostream>
#include <iterator> // for std::size

/**
 * 

   不要使用C语言风格字符串！
 * C语言风格字符串就是一个以空字符(\0)结尾的字符数组。
 * 空字符是一个特殊的字符('\0'， ascii 码为 0) ，用于表示字符的结尾。
 * 所以C语言风格字符串也被称为空字符结尾的字符串。
 */
int main()
{
    char myString[]{"string"};
    const int length{static_cast<int>(std::size(myString))};
    //  const int length{ sizeof(myString) / sizeof(myString[0]) }; // use instead if not C++17 capable
    std::cout << myString << " has " << length << " characters.\n";

    for (int index{0}; index < length; ++index)
        std::cout << static_cast<int>(myString[index]) << ' ';

    std::cout << '\n';

    // C语言风格字符串遵循与数组相同的规则。
    // 所以不能使用赋值操作符给它赋值
    char myString2[]{"string"}; // ok
    // myString2 = "rope"; // not ok!
    // 但是可以使用下标运算符[]来改变字符串中的元素
    myString2[1] = 'p';
    std::cout << myString2 << '\n';
    /*std::cout 会依次打印空字符。如果你不小心覆盖了字符串中的空字符（例如：给myString[6]赋值），
    那么你得到的打印结果不仅仅是完整的字符串，std::cout还会继续打印相邻内存中的内容，直到遇到 0。*/

    // 字符数组的大小比字符串大是可以的：“Alex” 会被打印出来，然后 std::cout 会在遇到空字符时停止打印。数组中后续内容会被忽略。
    char name[20]{"Alex"}; // only use 5 characters (4 letters + null terminator)
    std::cout << "My name is: " << name << '\n';

    return 0;
}