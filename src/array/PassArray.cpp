#include <iostream>

void passValue(int value) // value 是实参的副本
{
    value = 99; // 修改 value 的值不会影响原值
}

void passArray(int prime[5]) // prime 是数组本身
{
    prime[0] = 11; // 修改 prime 元素的值会实际修改数组
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

int main()
{
    int value{1};
    std::cout << "before passValue: " << value << '\n';
    passValue(value);
    std::cout << "after passValue: " << value << '\n';

    int prime[5]{2, 3, 5, 7, 11};
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';

    return 0;
}