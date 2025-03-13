#include <iostream>
#include <utility>

/**
 * 排序的原理
    排序通常是通过反复比较数组元素对来执行的，如果它们满足某些预定义的条件，则交换它们。
    根据使用的排序算法的不同，比较这些元素的顺序也不同。标准取决于列表将如何排序(例如，升序或降序)。
    要交换两个元素，可以使用c++标准库中的std::swap()函数，该函数在<utility>头文件中定义。
 */
int main()
{
    int x{2};
    int y{4};
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';

    return 0;
}