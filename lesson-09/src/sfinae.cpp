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
struct has_cache
{
    static void check(...);

    template<class U>
    static auto check(U* u) -> decltype(u->cache());

    static constexpr bool value = std::is_same<int, decltype(has_cache<T>::check(static_cast<T*>(nullptr)))>::value;
};

}

template<class T>
int calculate(T& t,
              typename std::enable_if<my::has_cache<T>::value>::type* = nullptr)
{
    std::cout << "Get cached value..." << std::endl;
    return t.cache();
}

template<class T>
int calculate(T& t,
              typename std::enable_if<!my::has_cache<T>::value>::type* = nullptr)
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
}
