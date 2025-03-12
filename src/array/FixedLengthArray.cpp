#include <iostream>

int main()
{
    int prime[5]{}; // hold the first 5 prime numbers
    prime[0] = 2;   // The first element has index 0
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)

    // 也可以使用初始化列表进行初始化
    int prime2[5]{ 2, 3, 5, 7, 11 };
    // 等价于
    // int prime2[]{ 2, 3, 5, 7, 11 };

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << '\n';

    return 0;
}