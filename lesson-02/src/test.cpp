#include <cassert>
#include <iostream>

#include "lib1.hpp"

int main()
{
    int a;
    int* ptr = nullptr; // Замена NULL

    std::cout << *ptr << std::endl;

    for (std::uint16_t i = 10; i >= 0; --i)
    {
        std::cout << i << std::endl;
        if (i > -10)
        {
            std::cout << i << std::endl;
        }
    }
    assert(square(4) == 16);
    assert(square(1, 2) == 100);
    return 0;
}
