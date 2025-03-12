#include <iostream>
#include <utility>

template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << ']';
}


/**
 * 因为在C++中使用一对数据是很常见的需求，因此C++标准库提供了一个名为std::pair的类模板(位于 <utility> 头文件中) ，
 * 它的定义和使用了多个模板类型的  Pair 类一样。实际上，我们可以使用 std::pair 来替换我们定义的pair。
 */
int main()
{
    std::pair<int, double> p1{1, 2.3}; // a pair holding an int and a double
    std::pair<double, int> p2{4.5, 6}; // a pair holding a double and an int
    std::pair<int, int> p3{7, 8};      // a pair holding two ints

    print(p2);

    return 0;
}