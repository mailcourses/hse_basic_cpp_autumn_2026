#include <iostream>

namespace my
{

struct Foo
{
    int cache()
    {
        return 42;
    }
};

struct Boo
{
    char cache()
    {
        return 's';
    }
};

template<class T>
concept HasCache =
    requires(T t) {
        { t.cache() } -> std::convertible_to<int>;
    };

} // namespace my

template<my::HasCache T>
int calculate(T& t)
{
    std::cout << "Get cached value..." << std::endl;
    return t.cache();
}

template<class T>
int calculate(T& t)
{
    int res{0};
    std::cout << "Caclulating value..." << std::endl;
    // Посчитать res
    return res;
}

int main()
{
    {
        int a;
        calculate(a);
    }
    {
        my::Foo a;
        calculate(a);
    }

    {
        my::Boo a;
        calculate(a);
    }
    return 0;
}

