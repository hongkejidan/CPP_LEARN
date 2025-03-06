#include <iostream>

using std::cout;
int main() {
    // 指向 const 的左值引用
    const int x { 5 };
    const int& ref { x };

    // const左值引用也可以绑定到可修改的左值
    int y { 6 };
    const int& ref1 { y };
    // ref1 = 7; // error: ref1 is const

    // 也可以使用右值初始化const左值引用
    /**
     * 临时对象通常在创建它们的表达式的末尾被销毁。
        但是，如果为保存右值 5 而创建的临时对象在初始化 ref 的表达式结束时被销毁，那么在上面的例子中会发生什么情况呢？引用ref 将变成悬垂引用(引用一个已经被销毁的对象)，当我们试图访问 ref 时，将产生未定义行为。
        为了避免这种情况下的悬垂引用，C++有一个特殊的规则：当const左值引用被绑定到一个临时对象时，临时对象的生存期将被扩展到与引用的生存期相匹配。
     */
    const int& ref2 { 5 };
    cout << "ref2 = " << ref2 << '\n';

    return 0;
}