#include <iostream>
#include <iterator> // For std::size
#include <string_view>

int main() {
  // No null-terminator.
  char vowels[]{'a', 'e', 'i', 'o', 'u'};

  // vowels 并没有包含结束符，我们需要传递长度
  // 因为 vowels 是数组，我们可以使用 std::size 来获取长度
  std::string_view str{vowels, std::size(vowels)};

  std::cout << str
            << '\n'; // 这是安全的。std::cout 知道如何打印 std::string_view.

  return 0;
}