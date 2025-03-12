#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void printEmployee(const Employee &e)
{
    // 由于对象的引用就是对象本身，因此可以使用点运算符来访问引用的成员
    std::cout << "Id: " << e.id << '\n';
    std::cout << "  Age: " << e.age << '\n';
    std::cout << "  Wage: " << e.wage << '\n';
}

int main()
{
    Employee joe{1, 34, 65000.0};

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    return 0;
}