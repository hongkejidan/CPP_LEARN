#include <iostream>

// 如果类型或对象使用的堆内存不超过两个字长则返回true
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

// 定义一个结构体, 该结构体的大小超过两个指针的大小, 所以返回false
struct S
{
    double a, b, c;
};

int main()
{
    std::cout << std::boolalpha; // 将bool类型打印为true或false，而不是01
    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false

    return 0;
}

/**
 * 如果sizeof(T) <= 2 * sizeof(void*)而且类型T没有额外的设置操作，则可以认为T的拷贝开销小。
 *  拷贝开销小的类型通常有：所有基本类型、枚举类型和std::string_view.
 *  拷贝开销大的类型通常有：std::array, std::string, std::vector, 和 std::ostream.
 */
