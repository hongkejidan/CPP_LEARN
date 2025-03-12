#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};
struct Company
{
    Employee CEO; // Employee is a struct within the Company struct
    int numberOfEmployees{};
    // 也可以将Employee定义为Company的一个嵌套类型
    // struct Employee
    // {
    //     int id{};
    //     int age{};
    //     double wage{};
    // };
};
int main()
{
    Company company {{1, 42, 60000.0}, 5};
    std::cout << company.CEO.wage << '\n'; // use the dot operator to access the wage of the CEO of the company
}
