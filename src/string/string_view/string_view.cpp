#include <iostream>
#include <string>
#include <string_view>

int main()
{
    // 以下代码，会将字符串"hello"复制3次，创建4个副本：字面量、text、str、more。
    char text[]{"hello"};
    std::string str{text};
    std::string more{str};

    std::cout << text << ' ' << str << ' ' << more << '\n';

    // 使用了string_view，"hello"只会在编译存储到二进制文件中，运行时不会再复制。
    std::string_view text1{"hello"}; // view the text "hello", which is stored in the binary
    std::string_view str1{text1};    // view of the same "hello"
    std::string_view more1{str1};    // view of the same "hello"

    std::cout << text1 << ' ' << str1 << ' ' << more1 << '\n';

    // string_view有string大部分功能
    std::string_view str2{"Trains are fast!"};

    std::cout << str2.length() << '\n';                  // 16
    std::cout << str2.substr(0, str2.find(' ')) << '\n'; // Trains
    std::cout << (str2 == "Trains are fast!") << '\n';   // 1

    // Since C++20
    // std::cout << str2.starts_with("Boats") << '\n'; // 0
    // std::cout << str2.ends_with("fast!") << '\n';   // 1

    std::cout << str2 << '\n'; // Trains are fast!
    std::cout << str2 << '\n'; // Trains are fast!
    // ！只读字符串优先使用string_view

    // 由于string_view不会创建字符串副本，所以当修改name时，yourName也被修改了。
    char name[]{"smile z"};
    std::string_view yourName{name};
    std::cout << yourName << std::endl;

    name[4] = 'y';
    std::cout << yourName << std::endl;

    // 修改string_view会改变观察对象，而不会修改原观察对象。
    yourName = "gua";
    std::cout << yourName << std::endl;
    std::cout << name << std::endl;

    return 0;
}