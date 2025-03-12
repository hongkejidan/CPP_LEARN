#include <iostream>

// Pair类模板的声明
// (由于不再使用定义，所以我们只需要声明)
template <typename T>
struct Pair;

// 显式定义Pair<int>的具体实现
template <> // 告诉编译器这是一个没有模板参数的模板类型
struct Pair<int>
{
    int first{};
    int second{};
};

// 显式定义Pair<double>的具体实现
template <> // 告诉编译器这是一个没有模板参数的模板类型
struct Pair<double>
{
    double first{};
    double second{};
};

constexpr int max(Pair<int> p)
{
    return (p.first > p.second ? p.first : p.second);
}

constexpr double max(Pair<double> p) // okay: overloaded function differentiated by parameter type
{
    return (p.first > p.second ? p.first : p.second);
}

int main()
{
    Pair<int> p1{5, 6}; // 实例化Pair<int>并创建对象p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double> p2{1.2, 3.4}; // 实例化Pair<double>并创建对象p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<double> p3{7.8, 9.0}; // 使用之前定义的Pair<double>创建对象p3
    std::cout << p3.first << ' ' << p3.second << '\n';

    std::cout << max(p1) << '\n';
    std::cout << max(p2) << '\n';

    return 0;
}