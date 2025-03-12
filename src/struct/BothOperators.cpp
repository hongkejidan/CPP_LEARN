#include <iostream>
#include <string>

struct Paw
{
    int claws{};
};

struct Animal
{
    std::string name{};
    Paw paw{};
};

int main()
{
    Animal puma{"Puma", {5}};

    Animal *ptr{&puma};

    // ptr is a pointer, use ->
    // paw is not a pointer, use .
    // 括号是可选的，添加括号可以提高代码的可读性
    std::cout << (ptr->paw).claws << '\n';

    std::cout << ptr->paw.claws << '\n';

    return 0;
}