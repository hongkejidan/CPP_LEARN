/**
 * 初始化C字符串常量的两种方法——固定数组和指针
        char myName[]{ "Alex" }; // 固定数组
        const char* myName{ "Alex" };//指向符号常量的指针
        符号常量方式初始化的C风格字符串，可能会位于内存中的只读区域，并且相同的字符串变量可能会指向同一块内存，因此最好定义为const
        符号常量方式初始化的C风格字符串位于只读内存中时，它具有全局作用域。
 */
#include <iostream>

int main() {
  char myName[]{"Alex"}; // 固定数组
  std::cout << myName << '\n';

  const char *yourName{"Alex"}; // 使用指针指向符号常量
  std::cout << yourName << '\n';

  // 编译器会出于性能优化的考量，将多个相同的字符串字面量合并为一个字符串值。例如：
  // 相当于Java中的字符串常量池的使用。
  const char *name1{"Alex"};
  const char *name2{"Alex"};

  // std::cout 和字符指针
  int nArray[5]{9, 7, 5, 3, 1};
  char cArray[]{"Hello!"};
  const char *name{"Alex"};
  /**
   * 为什么整型数组打印的就是地址，而字符数组就能打印字符串？
      这是因为 std::cout
   可以推断你的意图。如果你传入了一个非字符类型的指针，它会打印该指针的内容（指针持有的地址值）。
      但是，如果你传递的是一个 char* 或 const char*
   类型的对象，它会假定你希望打印的是一个字符串。
      因此，它打印的是指针指向的字符串的值而不是指针持有的地址值。
   */
  std::cout << nArray << '\n'; // nArray will decay to type int*
  std::cout << cArray << '\n'; // cArray will decay to type char*
  std::cout << name << '\n';   // name is already type char*

  char c{'Q'}; // 注意这里是一个字符
  std::cout << &c;  // 结果输出 Q + 乱码
                    /*   输出结果分析
                    实际输出示例（可能结果之一）：
                    Q�@ （后跟乱码，具体内容取决于内存布局）
                  
                    原因解析
                    1. 指针类型决定输出方式
                  
                    &c 的类型是 char*
                    std::cout 对 char* 的处理方式是将其作为 C风格字符串 输出
                    会从该地址开始连续输出字符，直到遇到 \0 终止符
                    内存实际内容
                  
                    2. 变量 c 的存储布局示例：
                    | c ('Q') | 未知内存内容 | ... | 0x00（偶然的终止符） |
                    std::cout 会输出：
                    'Q'（c的值）
                    后续内存中的每个字节被当作 char 输出
                    直到遇到 \0 才停止
                    未定义行为（UB）的体现
                  
                    3. 访问未分配的内存属于未定义行为
                    可能的表现包括：
                    输出乱码
                    程序崩溃（如果访问到受保护的内存页）
                    输出看似合理的字符串（如果后续内存恰好有 \0） */

  return 0;
}