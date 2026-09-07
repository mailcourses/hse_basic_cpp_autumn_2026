#include <iostream>
#include <cstdint>
#include <string>

struct Foo
{
    int a;
//private:
    double b;
};

namespace my
{
    using uint64_t = short int;
}

//using namespace my; <-- конфликт имён
using namespace std;

void ffoo(float arg)
{
    std::cout << "float" << std::endl;
}

void ffoo(double arg)
{
    std::cout << "double" << std::endl;
}

void ffoo(long double arg)
{
    std::cout << "long double" << std::endl;
}

int main()
{
    Foo foo{10, 20.0};
    std::cout << foo.a << "\t" << foo.b << std::endl;
    std::uint64_t c; // 0...2**64 - 1
    std::int64_t d; // [бит под знак][...] -2**63 ... 2**63-1

    std::cout << sizeof(c) << " " << sizeof(d) << std::endl;
    float e = 0.1;
    ffoo(e);
    ffoo(0.1);
    ffoo(0.1L);

    int8_t f = 10;
    std::cout << "[" << static_cast<int>(f) << "]" << std::endl;
    int h();
    // h = 10; <-- компилятор считает, что h -- это функция
    std::string str1{"Hello kitty"};
    std::cout << "size: " << str1.size() << std::endl;
    std::cout << "size capacity: " << str1.capacity() << std::endl;
    std::cout << "str[1]: " << str1[1] << std::endl;
    std::cout << "substr: " << str1.substr(4, 3) << std::endl;
    str1.clear();
    std::cout << "size: " << str1.size() << std::endl;
    std::cout << "size capacity: " << str1.capacity() << std::endl;
    str1 += " and dog";
    std::string str2 = str1.substr(4, 3);
    std::cout << std::boolalpha << (str1 == str2) << std::endl;
    std::cout << "str1: " << str1 << std::endl;

    std::string input;
    std::cin >> input; // std::cin.operator>>(input);
    std::cout << "input: " << input << std::endl;
}
