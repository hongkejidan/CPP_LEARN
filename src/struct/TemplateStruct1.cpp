#include <iostream>

template <typename T, typename V>
struct Pair
{
    T first{};
    T second{};
    V third{};
    V four{};
};

int main()
{
    Pair<int, double> p1{5, 6, 1.1, 2.2}; // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << ' ' << p1.third << ' ' << p1.four << std::endl;

    Pair<double, int> p2{1.2, 3.4, 33, 23}; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << ' ' << p2.third << ' ' << p2.four << std::endl;

    Pair<double, std::string> p3{7.8, 9.0, "鸡你", "太美"}; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << ' ' << p3.third << ' ' << p3.four << std::endl;

    return 0;
}