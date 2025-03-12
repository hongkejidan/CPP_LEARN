#include <iostream>
enum class Color // "enum class" 定义了有作用域枚举类型
{
    red, // red 是 Color 作用域的成员
    blue,
};

enum class Fruit
{
    banana, // banana 是 Fruit 作用域的成员
    apple,
};

// 通过重载运算符<<来打印枚举类型
std::ostream &operator<<(std::ostream &out, Color color)
{
    switch (color)
    {
    case Color::red:
        out << "red";
        break;
    case Color::blue:
        out << "blue";
        break;
    default:
        out << "???";
        break;
    }

    return out;
}

int main()
{

    Color color{Color::red};    // 注意: red 不能够被直接访问，必须使用 Color::red
    Fruit fruit{Fruit::banana}; // note: banana 不能够被直接访问, 必须使用 Fruit::banana

    /* if (color == fruit) // 编译错误：编译器不知道如何比较 Color 和 Fruit
        std::cout << "color and fruit are equal\n";
    else
        std::cout << "color and fruit are not equal\n"; */

    // 有作用域枚举不会被隐式转换为整型，也不会进行整型比较
    Color shirt{Color::red};

    if (shirt == Color::red) // Color 和 Color 的比较是可以的
        std::cout << "The shirt is red!\n";
    else if (shirt == Color::blue)
        std::cout << "The shirt is blue!\n";

    // 如果没有为 Color 定义输出运算符，下面的代码会导致编译错误
    std::cout << shirt << std::endl; // 编译错误：没有为 Color 定义输出运算符
    return 0;
}