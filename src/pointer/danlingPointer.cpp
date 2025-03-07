#include <iostream>

// 悬垂指针：指针指向的内存已经被释放，但指针仍然保留着之前指向的地址，这种指针被称为悬垂指针。
int main()
{
    int x{ 5 };
    int* ptr{ &x };

    std::cout << *ptr << '\n'; // valid

    {
        int y{ 6 };
        ptr = &y;

        std::cout << *ptr << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behavior from dereferencing a dangling pointer

    return 0;
}


/**
 * 在C++中，当一个变量超出其作用域时，它的生命周期结束，内存可能会被释放或重新分配给其他用途。然而，指针仍然可能保留着之前指向的地址，即使该地址的内存已经不再有效。这种情况下，指针被称为**悬垂指针**（dangling pointer）。

在你的代码中，`y` 是一个局部变量，它在其所在的块作用域（即 `{}` 内部）结束时被销毁。然而，指针 `ptr` 仍然保留着 `y` 的地址。当你尝试通过 `ptr` 访问这个地址时，行为是**未定义的**（undefined behavior）。

### 为什么 `ptr` 仍然指向 `y` 的值？
1. **指针保留地址**：在 `y` 被销毁后，`ptr` 仍然保留着 `y` 的地址。C++ 不会自动将指针设置为 `nullptr` 或其他值。
2. **未定义行为**：当你通过 `ptr` 访问这个地址时，你实际上是在访问一个已经不再有效的内存位置。虽然在某些情况下，你可能仍然会看到 `y` 的值，但这只是巧合，因为内存可能还没有被其他数据覆盖或重新分配。
3. **编译器行为**：不同的编译器和运行时环境可能会以不同的方式处理悬垂指针。在某些情况下，内存可能暂时保持不变，导致你仍然看到 `y` 的值，但这并不意味着代码是正确的或可移植的。

### 如何避免悬垂指针？
1. **在指针超出作用域后置为 `nullptr`**：
   ```cpp
   {
       int y{ 6 };
       ptr = &y;
       std::cout << *ptr << '\n'; // valid
   }
   ptr = nullptr; // 避免悬垂指针
   ```
2. **使用智能指针**：C++11 引入了智能指针（如 `std::unique_ptr` 和 `std::shared_ptr`），它们可以自动管理内存，避免悬垂指针的问题。
3. **避免返回局部变量的地址**：确保不要返回局部变量的地址给调用者，因为局部变量会在函数结束时销毁。

### 总结
`ptr` 在 `y` 超出作用域后仍然指向 `y` 的地址，但这是一个悬垂指针，访问它是未定义行为。虽然在某些情况下你可能仍然看到 `y` 的值，但这并不意味着代码是正确的。应该采取措施避免悬垂指针，例如将指针置为 `nullptr` 或使用智能指针。
 * 
 * 
 * 
 * 
 * 
 */