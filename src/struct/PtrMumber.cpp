#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee joe{1, 34, 65000.0};

    ++joe.age;
    joe.wage = 68000.0;

    Employee *ptr{&joe};
    // std::cout << ptr.id << '\n'; // 必须对ptr解引用才能访问成员
    std::cout << (*ptr).id << '\n'; // 使用箭头运算符访问指针指向的成员,不够优雅

    // 使用箭头运算符访问指针指向的成员，最佳实践
    std::cout << ptr->id << '\n'; 
    return 0;
}