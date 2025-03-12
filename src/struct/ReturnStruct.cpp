#include <iostream>

struct Point3d
{
    double x{0.0};
    double y{0.0};
    double z{0.0};
};

// 结构体通常按值返回，这样就不会产生悬垂引用
Point3d getZeroPoint()
{
    // We can create a variable and return the variable (we'll improve this below)
    Point3d temp{0.0, 0.0, 0.0};
    return temp;

    // 返回一个匿名结构体
    // return {0.0, 0.0, 0.0};
    // 或者
    // return Point3d{0.0, 0.0, 0.0};
    // 或者
    // return {};
    // 或者
    // return Point3d{};

}

int main()
{
    Point3d zero{getZeroPoint()};

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}