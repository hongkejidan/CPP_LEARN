#include <iostream>
#include <string>
#include <string_view>

/**
 * 如果我们想写一个接受字符串形参的函数，将形参设置为 std::string_view 是最灵活的选择，
 *  因为它可以高效地配合C风格的字符串参数(包括字符串字面量)、
 *  std::string参数(将隐式转换为std::string_view ‘)
 *  和 std::string_view参数来工作：
 */
void printSV(std::string_view sv)
{
    sv.remove_prefix(2);
    std::cout << sv << '\n';
}

int main()
{
    std::string s{"Hello, world"};
    std::string_view sv{s};

    printSV(s);              // ok: pass std::string
    printSV(sv);             // ok: pass std::string_view
    printSV("Hello, world"); // ok: pass C-style string literal

    std::cout << s << '\n';
    return 0;
}