#include <iostream>
// 最佳实践：将枚举定义在命名空间中
namespace Animals
{
    enum Animals
    {
        CAT,    // 0
        DOG,    // 1
        PIG,    // 2
        HORSE,  // 3
        GIRAFFE // 4
    };
}
namespace Colors
{
    enum Colors
    {
        RED,
        BLUE,
        GREEN,
        YELLOW,
        WHITE
    };
}

// Teach operator<< how to print a Color
// Consider this magic for now since we haven't explained any of the concepts it uses yet
// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream &operator<<(std::ostream &out, Colors::Colors color)
{
    switch (color)
    {
    case Colors::RED:
        out << "red";
        break;
    case Colors::BLUE:
        out << "blue";
        break;
    case Colors::GREEN:
        out << "green";
        break;
    case Colors::YELLOW:
        out << "yellow";
        break;
    case Colors::WHITE:
        out << "white";
        break;
    default:
        out << "???";
        break;
    }

    return out;
}
// 通过重载运算符<<来打印枚举类型
std::ostream &operator<<(std::ostream &out, Animals::Animals animal)
{
    switch (animal)
    {
    case Animals::CAT:
        out << "cat";
        break;
    case Animals::DOG:
        out << "dog";
        break;
    case Animals::PIG:
        out << "pig";
        break;
    case Animals::HORSE:
        out << "horse";
        break;
    case Animals::GIRAFFE:
        out << "giraffe";
        break;
    default:
        out << "???";
        break;
    }

    return out;
}

// 也可以通过重载运算符>>来输入枚举类型
std::istream &operator>>(std::istream &in, Animals::Animals &animal)
{
    int input{};
    in >> input; // input an integer

    animal = static_cast<Animals::Animals>(input);
    return in;
}

int main()
{

    Animals::Animals myAnimal{Animals::CAT};

    Colors::Colors myColor{Colors::BLUE};

    std::cout << "I have a " << myColor << " " << myAnimal << std::endl;

    // 整型可以转换为枚举类型，需要使用static_cast来进行强制转换
    Animals::Animals myAnimal2{static_cast<Animals::Animals>(2)};
    std::cout << "I have a " << myColor << " " << myAnimal2 << std::endl;

    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=horse, 4=giraffe): ";

    // 例如，不能直接从控制台输入一个枚举，但是可以输入一个整型，将其转换为枚举。
    int input{};
    std::cin >> input; // input an integer

    Animals::Animals pet{static_cast<Animals::Animals>(input)}; // static_cast our integer to a Pet
    std::cout << "You chose a " << pet << std::endl;

    std::cout << "Enter a pet (0=cat, 1=dog, 2=pig, 3=horse, 4=giraffe): ";
    Animals::Animals pet2{};
    std::cin >> pet2;
    std::cout << "You chose a " << pet2 << std::endl;

    enum Color
    {
        red,
        blue,
    };

    enum Fruit
    {
        banana,
        apple,
    };

    Color color{red};
    Fruit fruit{banana};

    // 无作用域枚举类型不会进行类型检查，可以直接进行比较，但是不推荐这样做
    if (color == fruit)                             // 编译器会将 color 和 fruit 当做整型进行比较
        std::cout << "color and fruit are equal\n"; // 并认为它们相等
    else
        std::cout << "color and fruit are not equal\n";
    return 0;
}