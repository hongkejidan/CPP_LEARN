
struct Employee
{
    int id{};
    int age{};
    double wage{};
};

/**
 * 如果聚合对象定义时有初始化值列表（实例化的同时初始化）：

        如果具有显式的初始化值，则使用该值；
        如果有缺失的初始化值，但存在默认初始化值，则使用默认值进行默认初始化；
        如果有缺失的初始化值，但是没有默认初始化值，则使用值初始化。
        如果聚合对象定义时没有初始化值列表（实例化时未进行初始化）：

        如果有默认初始化值，则使用默认值进行默认初始化；
        如果不存在默认初始化值，则对应成员保持未初始化状态。
 */
struct Something
{
    int x;    // no default initialization value (bad)
    int y{};  // value-initialized by default
    int z{2}; // explicit default value
};

// 最佳实践：为所有成员提供默认值。这确保了即使变量定义不包含初始化列表，成员也会被初始化。
struct Fraction
{
    int numerator{}; // we should use { 0 } here, but for the sake of example we'll use value initialization instead
    int denominator{1};
};

int main()
{
    Employee joe{2, 28, 45000.0};      // 使用大括号列表的列表初始化（推荐）
    Employee frank = {1, 32, 60000.0}; // 拷贝列表初始化，使用大括号
    // Employee robert ( 3, 45, 62500.0 );  // 使用小括号的直接初始化(C++20)

    Something s1;          // 未初始化：s1.x, s1.y, and s1.z 保持未初始化状态
    Something s2{5, 6, 7}; // 显式初始化器：S2.X，S2.Y和S2.Z使用显式值（不使用默认值）
    Something s3{};        // 缺少初始化器：S3.X是【值初始化的】，S3.Y和S3.Z使用默认值

    Fraction f1;       // f1.numerator value initialized to 0, f1.denominator defaulted to 1
    // ！！！！【最佳实践：如果没有为聚合提供显式初始化值，则首选值初始化(带空大括号初始化器)而不是默认初始化(不带大括号)。】
    Fraction f2{};     // f2.numerator value initialized to 0, f2.denominator defaulted to 1
    Fraction f3{6};    // f3.numerator initialized to 6, f3.denominator defaulted to 1
    Fraction f4{5, 8}; // f4.numerator initialized to 5, f4.denominator initialized to 8

    return 0;
}