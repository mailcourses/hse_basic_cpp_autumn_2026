#include "utils.hpp"
#include "dog.hpp"
#include "cat.hpp"

static int square(int num)
{
    return num * num;
}

int square(double num)
{
    return num * num;
}

struct Foo
{
    void foo()
    {
    }

    static void boo()
    {
    }
};

/*[[noreturn]]
void log_and_throw(const std::string& message)
{
    //std::cout << message << std::endl;
    throw 10;
}*/

[[gnu::fastcall]]
void example(int, int, int, int)
{
}

void example(int, int, int, int, int, int, int, int)
{
}

void foo()
{
    example(1, 2, 3, 4);
}

void boo()
{
    square(10);
    example(1, 2, 3, 4, 5, 6, 7, 8);
}

template <class T>
class Less
{
    const T& x_;
    public:
        Less(const T& x) : x_(x) {}
        bool operator()(const T& y) const
        {
            return y < x_;
        }
};

int main()
{
    Foo foo;
    foo.foo();
    foo.boo();
    Foo::boo();

    [[likely]]
    if (square(4) < 10)
    {
        // ...
    }
    else
    {
        // ...
    }
    //log_and_throw("hello");
    //Foo::foo();
    Less<int> lessThen3(3);
    bool result = lessThen3.operator()(5); // false

    return calculate(10, 20) + dog() + cat();
}
