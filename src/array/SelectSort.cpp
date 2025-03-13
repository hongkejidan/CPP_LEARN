#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 50, 20, 10, 40 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    // 遍历数组中的每个元素
    // （最后一个元素不需要遍历，因为当我们处理到它时它已经排好序了）
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        // smallestIndex 是本轮迭代中找到的最小元素的索引
        // 首先假设本轮第一个元素就是最小的
        int smallestIndex{ startIndex };

        // 然后在数组剩余部分中寻找更小的元素
        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            // 如果找到比当前记录的最小元素更小的元素
            if (array[currentIndex] < array[smallestIndex])
                // 则更新最小元素的索引
                smallestIndex = currentIndex;
        }

        // 现在 smallestIndex 是剩余数组中的最小元素
        // 将起始元素与最小元素交换（将其放到正确的位置）
        std::swap(array[startIndex], array[smallestIndex]);
    }

    // 现在整个数组已排序，打印排序后的数组作为验证
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
