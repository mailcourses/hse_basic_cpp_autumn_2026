#include <iostream>

struct Foo
{
    using type = int;
    type a;
    char b;
    static const int32_t magic = 1234;
};

template<class T>
struct Foo2
{
    using type = T*;
    type a;
    char b;
    static const int32_t magic = 1234;
};

std::ostream& operator<<(std::ostream& os, const Foo& foo)
{
    os << "Foo{" << foo.a << ", " << foo.b << "}";
    return os;
}

template<class T>
void printLine(const T& value)
{
    std::cout << value << std::endl;
}

template<class T>
struct A
{
    typename Foo2<T>::type internal;
    //Foo::magic;
};

int main()
{
    printLine("Hello, world!");
    printLine(100500);
    printLine(Foo{10, 'b'});
    A<int> a;
    std::cout << a.internal << std::endl;
    return 0;
}
