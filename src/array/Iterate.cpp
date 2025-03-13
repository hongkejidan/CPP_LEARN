#include <iostream>
#include <iterator> // for std::size  需要C++17


/**
 * 数组的循环遍历通常被用来完成以下三件事：
    计算数值 (例如：平均值或总和)；
    查找某个值（例如：最大值、最小值）；
    数组排序（例如：升序、降序）。
 */
int main()
{
    // scores are 0 (worst) to 100 (best)
    constexpr int scores[]{84, 92, 76, 81, 56};
    constexpr int numStudents{static_cast<int>(std::size(scores))};

    int maxScore{0}; // keep track of our largest score
    for (int student{0}; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
        }
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
}