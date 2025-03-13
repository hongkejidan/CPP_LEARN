#include <cstring>
#include <iostream>

int main()
{
    char source[]{"Copy this!"};
    char dest[50];
    std::strcpy(dest, source);
    std::cout << dest << '\n'; // prints "Copy this!"

    // 如果目标字符串大小不足以容纳全部字符串，会导致数组溢出
    char dest2[5];
    std::strcpy(dest2, source);
    /**
     * dest2内存布局（假设从地址0x100开始）：
        地址: 0x100 0x101 0x102 0x103 0x104 0x105 0x106 ...
        内容:  C     o     p     y     空格   t     h     i     s     !    \0
            |-----------数组边界-----------|  |----------溢出部分----------|

        风险：   破坏了dest2之后的内存数据
                可能触发栈保护错误（取决于编译器）
                存在安全漏洞（缓冲区溢出攻击的常见目标）
     * 
     */
    std::cout << dest2 << '\n';

    for (long i{0}; i < static_cast<int>(std::size(dest2)); ++i) {
        std::cout << dest2[i] << '\n';
    }


    // 使用strcpy_s
    char dest3[5]; // note that the length of dest is only 5 chars!
    strcpy_s(dest3, 5, source); // A runtime error will occur in debug mode
    std::cout << dest3 << '\n';
    /**
     * 可能的两种情况：
     *      1. 运行时错误触发
            strcpy_s 会检测目标缓冲区大小是否足够
            "Copy this!" 需要 11 字节（10字符+1终止符）
            目标缓冲区只有5字节，明显不够
            在 Debug 模式下，会触发断言失败（assertion failure），程序终止

            2. Release 模式下的"妥协"行为（非标准但常见）-----本机出现的情况
            如果程序继续执行（如某些编译器不强制执行）：
            strcpy_s 会将目标缓冲区第一个字节设为 \0
            剩余内容保持不变（但不会被写入源字符串内容）
            函数返回非零错误码
     */

    return 0;
}