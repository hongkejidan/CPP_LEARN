#ifndef PAIR_H
#define PAIR_H
// 类模板通常定义在头文件中，因此可以被包含到其他任何需要它们的代码中。
template <typename T>
struct Pair
{
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first > p.second ? p.first : p.second);
}

#endif