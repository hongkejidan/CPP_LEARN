#include <utility>
#include <string>

int main() {

    std::pair<int, int> p1{ 1, 2 };
    std::pair<std::string, std::string> p2{"nb", "牛逼"};

    // 从C++ 17开始，当从类模板实例化一个对象时，编译器可以从对象的初始化式的类型推断出模板类型(类模板实参推断，简称CTAD)
    std::pair p3 { 2.2, 1L};

    // std::pair<> p4 { 1, 2 };    // 错误: 模板参数太少, 两个参数都不会推断
    // std::pair<int> p5 { 3, 4 }; // 错误: 模板参数太少,第二个参数不会被推断
    return 0;
}