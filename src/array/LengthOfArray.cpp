#include <iostream>
#include <iterator>

/**
 * 
 * 
 * printSize函数编译不通过的原因是std::size函数不能直接用于数组指针。
 * 在C++中，数组作为函数参数传递时，实际上传递的是指向数组首元素的指针，而不是整个数组。
 * 因此，printSize函数中的参数int array[]实际上是一个指针，而不是数组。
 *  std::size函数只能用于数组或标准库容器（如std::vector、std::array等），而不能用于指针。因为指针并不包含数组的大小信息，所以编译器无法通过指针获取数组的大小。
 */
void printSize(int array[])
{
    // std::cout << std::size(array) << '\n'; // Error
}

int main()
{
    int array[]{1, 1, 2, 3, 5, 8, 13, 21};
    std::cout << std::size(array) << '\n'; // will print the size of the array
    printSize(array);
    // sizeof也可以用于数组，会返回数组元素的大小
    std::cout << sizeof(array) << '\n'; // will print the size of the array multiplied by the size of an int
    std::cout << sizeof(int) << '\n';
    // 经典技巧：将数组的大小除以数组元素的大小，就可以得到数组的长度。
    std::cout << "The array has: " << sizeof(array) / sizeof(array[0]) << " elements\n";

    // 数组访问越界，C++ 不会检查下标是否合法。13 的值会被插入到内存中（第 12 个元素位置的内存可用的话）。
    // 当这种情况发生时，将得到未定义的行为——例如，这可能会覆盖另一个变量的值，或导致程序崩溃。
    array[10] = 13;
    std::cout << array[8] << std::endl;

    return 0;
}