#include <iostream>

int main()
{
    char name[10]{}; // 最多输入9个字符，最后一个是空字符表示字符串结尾。
    std::cout << "Enter your name: ";
    // 下面代码无法阻止用户输入超过9个字符。当输入超过9个字符时，会出现异常。
    // std::cin >> name;
    // 正确的做法，最多读取数字符串长度个字符。
    std::cin.getline(name, std::size(name));
    std::cout << "You entered: " << name << '\n';

    /**
     * Enter your name: 6666666666666666666666666666666666
     *  You entered: 666666666
     * 
     */

    return 0;
}